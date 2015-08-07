n = int(input())
spaces=len(str(bin(n)[2:]))
string=' '
for i in range(spaces):
	string+=' '
for x in range(1,n+1):
	#print len(str(x))
	print string[len(str(x))+1:]+str(x)+string[len(str(oct(x)[1:])):]+oct(x)[1:]+string[len(hex(x)[2:]):]+hex(x)[2:].upper()+string[len(bin(x)[2:])-1:]+bin(x)[2:]
    	#print oct(x)[1:],hex(x)[2:],bin(x)[2:]