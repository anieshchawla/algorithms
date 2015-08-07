string = raw_input()
_iter = 1
output=[]
output.append(string[0])
string1=''
while(_iter<len(string)):
	if(string[_iter]=='|'):
		_iter+=2
		string2=''
		while(_iter < len(string) and string[_iter] not in '&' and string[_iter] not in '|' ):
			string2+=string[_iter]
			_iter+=1
		output.append(string2)
	elif(string[_iter]=='&'):
		_iter+=2
		string2=''
		while(_iter < len(string) and string[_iter] not in '&' and string[_iter] not in '|'):
			string2+=string[_iter]
			_iter+=1
		output = map(lambda x:x+string2,output)
	else:
		string1+=string[_iter]
		output = map(lambda x:x+string1,output)
		_iter+=1
print output