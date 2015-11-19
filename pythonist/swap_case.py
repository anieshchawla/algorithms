string = raw_input()
output=''
for s in string:
	if s.isupper():
		output+=s.lower()
	else:
		output+=s.upper()

print output