import cs50

print("O hai! ",end="")
while True:
    print("How much change is owed?")
    n=cs50.get_float()
    if n>0:
        break
cents = round(n*100)
coins = 0
while cents>=25:
    cents-=25
    coins+=1
while cents>=10:
    cents-=10
    coins+=1
while cents>=5:
    cents-=5
    coins+=1
coins=coins+cents
print(coins)
