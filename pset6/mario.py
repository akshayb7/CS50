import cs50

def main():
    while True:
        print("Height: ",end="")
        n=cs50.get_int()
        if n>0 and n<=23:
            break
    space = n-1
    for i in range(n):
        print(" "*space + "#"*(i+2))
        space-=1


if __name__ == "__main__":
    main()