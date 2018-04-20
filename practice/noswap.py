def main():
    x = 1
    y = 2

    print("x is {}".format(x))
    print("y is {}".format(y))
    print("swapping...")
    swap(x,y)
    print("swapped")
    print("x is {}".format(x))
    print("y is {}".format(y))

def swap(a,b):
    temp = a
    a = b
    b = temp

if __name__ == "__main__":
    main()