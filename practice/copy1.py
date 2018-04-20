import cs50

print("s: ", end="")
s=cs50.get_string()

if s==None:
    exit(1)

t=s.capitalize()
print("s is {}".format(s))
print("t is {}".format(t))

exit(0)