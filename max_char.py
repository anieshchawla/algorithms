string = raw_input()
array = [0]*26

for _char in string:
	array[ord(_char) - ord('a')]+=1
max_num=0
index = 0
for i in range(26):
	if(max_num<array[i]):
		max_num=array[i]
		index = i

print chr(ord('a')+index)