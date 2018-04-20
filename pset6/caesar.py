import cs50
import sys

def main():
    if not len(sys.argv)==2:
        print("Error! Please pass a correct key")
        print("Usage: Python caesar.py key")
        exit(1)
    key=int(sys.argv[1])
    print("plaintext: ",end="")
    plaintext=cs50.get_string()
    print("ciphertext: ",end="")
    for c in plaintext:
        if c.isupper():
            print (chr(((ord(c)+key-65)%26)+65),end="")
        elif c.islower():
            print (chr(((ord(c)+key-97)%26)+97),end="")
        else:
            print (c,end="")
    print()
    exit(0)

if __name__=="__main__":
    main()