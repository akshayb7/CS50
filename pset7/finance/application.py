from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, url_for
from flask_session import Session
from passlib.apps import custom_app_context as pwd_context
from tempfile import mkdtemp

from helpers import *

# configure application
app = Flask(__name__)

# ensure responses aren't cached
if app.config["DEBUG"]:
    @app.after_request
    def after_request(response):
        response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
        response.headers["Expires"] = 0
        response.headers["Pragma"] = "no-cache"
        return response

# custom filter
app.jinja_env.filters["usd"] = usd

# configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

@app.route("/")
@login_required
def index():
    # select each symbol owned by the user and it's amount
    portfolio_symbols = db.execute("SELECT shares, symbol FROM portfolio WHERE id = :id", id=session["user_id"])

    # create a temporary variable to store TOTAL worth ( cash + share)
    total_value = 0

    # update each symbol prices and total
    for portfolio_symbol in portfolio_symbols:
        symbol = portfolio_symbol["symbol"]
        shares = portfolio_symbol["shares"]
        stock = lookup(symbol)
        total = shares * stock["price"]
        total_value += total
        db.execute("UPDATE portfolio SET price=:price, total=:total WHERE id=:id AND symbol=:symbol", \
                    price=usd(stock["price"]), total=usd(total), id=session["user_id"], symbol=symbol)

    # update user's cash in portfolio
    updated_cash = db.execute("SELECT cash FROM users WHERE id=:id", id=session["user_id"])

    # update total cash -> cash + shares worth
    total_value += updated_cash[0]["cash"]

    # print portfolio in index homepage
    updated_portfolio = db.execute("SELECT * from portfolio \
                                    WHERE id=:id", id=session["user_id"])

    return render_template("index.html", stocks=updated_portfolio, cash=usd(updated_cash[0]["cash"]), total= usd(total_value) )

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method=="POST":
        # check if symbol is valid
        stock=lookup(request.form.get("symbol"))
        if not stock:
            return apology("Invalid symbol")

        #check if number of shares entered is a positive integer
        try:
            numberofshares = int(request.form.get("shares"))
            if numberofshares < 0:
                return apology("Invalid shares number! Please enter a positive integer")
        except:
            return apology("Invalid shares number! Please enter a positive integer")

        cash=db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])

        #check if user has enough cash for purchase
        if not cash:
            return apology("Insufficient cash available for the purchase")
        elif float(cash[0]["cash"])<stock["price"]*numberofshares:
            return apology("Insufficient cash available for the purchase")
        else:
            #select the shares of that symbol from users account
            u_share=db.execute("SELECT shares FROM portfolio WHERE id= :id AND symbol= :symbol", \
                                id=session["user_id"],symbol=stock["symbol"])

            #if user does not have that share symbol, create it
            if not u_share:
                db.execute("INSERT INTO portfolio (name, shares, price, total, symbol, id) \
                            VALUES(:name, :shares, :price, :total, :symbol, :id)", \
                            name=stock["name"], shares=numberofshares, price=usd(stock["price"]), \
                            total=usd(numberofshares * stock["price"]), symbol=stock["symbol"], id=session["user_id"])

            #if user already has shares of that type
            else:
                shares_total = u_share[0]["shares"] + numberofshares
                db.execute("UPDATE portfolio SET shares=:shares WHERE id=:id AND symbol=:symbol", \
                            shares=shares_total, id=session["user_id"], symbol=stock["symbol"])

            # update user cash
            db.execute("UPDATE users SET cash = cash - :purchase WHERE id = :id", \
                        purchase=stock["price"] * float(numberofshares),id=session["user_id"])

            # update history
            db.execute("INSERT INTO histories (symbol, shares, price, id) VALUES(:symbol, :shares, :price, :id)", \
                        symbol=stock["symbol"], shares=numberofshares, price=usd(stock["price"]), id=session["user_id"])

        # return to index
        return redirect(url_for("index"))

    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    histories = db.execute("SELECT * from histories WHERE id=:id", id=session["user_id"])
    if not histories:
        return apology("Sorry! No history to show")

    return render_template("history.html", histories=histories)

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in."""

    # forget any user_id
    session.clear()

    # if user reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username")

        # ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password")

        # query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))

        # ensure username exists and password is correct
        if len(rows) != 1 or not pwd_context.verify(request.form.get("password"), rows[0]["hash"]):
            return apology("invalid username and/or password")

        # remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # redirect user to home page
        return redirect(url_for("index"))

    # else if user reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")

@app.route("/logout")
def logout():
    """Log user out."""

    # forget any user_id
    session.clear()

    # redirect user to login form
    return redirect(url_for("login"))

@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():

    #if request method is post then look for the symbol
    if request.method == "POST":
        quot=lookup(request.form.get("symbol"))

        # if symbol is not foud
        if not quot:
            return apology("Symbol not available! Please enter a valid symbol")
        return render_template("quoted.html",stock=quot)

    # if request method is not post
    else:
        return render_template("quote.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    # if user reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # check if username is provided
        if not request.form.get("username"):
            return apology("Missing Username!")

        # ensure password and confirm password fields are same
        elif  request.form.get("password") != request.form.get("confirm_password"):
            return apology("Passwords must match!")

        elif not request.form.get("password"):
            return apology("Password cannot be blank!")

        elif not request.form.get("confirm_password"):
            return apology("Password cannot be blank!")

        hash = pwd_context.encrypt(request.form.get("password"))

        # insert the new user into users, storing the hash of the user's password
        result = db.execute("INSERT INTO users (username, hash) VALUES(:username, :hash)", \
                             username=request.form.get("username"), hash=hash)

        #if username already exists
        if not result:
            return apology("Username already exist")

        # store id in session to log them in automatically
        user_id = db.execute("SELECT id FROM users WHERE username IS :username", username=request.form.get("username"))
        session['user_id'] = user_id[0]['id']

        # redirect user to home page
        return redirect(url_for("index"))

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    if request.method == "GET":
        return render_template("sell.html")
    else:
        # ensure proper symbol
        stock = lookup(request.form.get("symbol"))
        if not stock:
            return apology("Invalid Symbol")

        # ensure proper number of shares
        try:
            shares = int(request.form.get("shares"))
            if shares < 0:
                return apology("Shares must be positive integer")
        except:
            return apology("Shares must be positive integer")

        # select the symbol shares of that user
        user_shares = db.execute("SELECT shares FROM portfolio WHERE id = :id AND symbol=:symbol", \
                                 id=session["user_id"], symbol=stock["symbol"])

        # check if enough shares to sell
        if not user_shares or int(user_shares[0]["shares"]) < shares:
            return apology("Not enough shares")

        # update history of a sell
        db.execute("INSERT INTO histories (symbol, shares, price, id) VALUES(:symbol, :shares, :price, :id)", \
                    symbol=stock["symbol"], shares=-shares, price=usd(stock["price"]), id=session["user_id"])

        # update user cash (increase)
        db.execute("UPDATE users SET cash = cash + :purchase WHERE id = :id",id=session["user_id"], \
                    purchase=stock["price"] * float(shares))

        # decrement the shares count
        shares_total = user_shares[0]["shares"] - shares

        # if after decrement is zero, delete shares from portfolio
        if shares_total == 0:
            db.execute("DELETE FROM portfolio WHERE id=:id AND symbol=:symbol", \
                        id=session["user_id"], symbol=stock["symbol"])
        # otherwise, update portfolio shares count
        else:
            db.execute("UPDATE portfolio SET shares=:shares \
                    WHERE id=:id AND symbol=:symbol", \
                    shares=shares_total, id=session["user_id"], \
                    symbol=stock["symbol"])

        # return to index
        return redirect(url_for("index"))

@app.route("/account", methods=["GET", "POST"])
def account():
    """Change user password"""
    # manipulate the information the user has submitted
    if request.method == 'POST':

        # ensure old password was submitted
        if not request.form.get('password'):
            return apology("must provide old password")

        # query database for username
        rows = db.execute("SELECT * FROM users WHERE id = :id", id=session['user_id'])

        # ensure password is correct
        if not pwd_context.verify(request.form.get("password"), rows[0]['hash']):
            return apology("old password invalid")

        # ensure new password was submitted
        if not request.form.get("new-password"):
            return apology("Please provide new password")

        if not request.form.get("password-confirm"):
            return apology("Please provide password confirmation")

        # ensure password and confirmation match
        if not request.form.get("new-password") == request.form.get("password-confirm"):
            return apology("passwords must match")

        # store the hash of the password and not the actual password that was typed in
        hash = pwd_context.hash(request.form.get("new-password"))

        # username must be a unique field
        result = db.execute("UPDATE users SET hash=:hash WHERE id=:id", hash=hash, id=session['user_id'])
        if not result:
            return apology("Please try again")

        return render_template("success.html")

    else:
        return render_template("account.html")
