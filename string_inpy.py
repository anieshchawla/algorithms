string = raw_input()
a,b=raw_input().split(" ")
a=int(a)
string=string[:a]+b+string[a+1:]
print string