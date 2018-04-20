import cs50

c = cs50.get_char()
if c == "Y" or c == "y":
    print("Yes")
elif c == "N" or c == "n":
    print("No")
else:
    print("Error")
