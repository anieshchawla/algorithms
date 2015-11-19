array_list = [0]*26
string = raw_input()

for s in string:
	array_list[ord(s)-97]+=1

for x in range(3):
	max_num = max(array_list)
	index = array_list.index(max_num)
	print chr(index+97), max_num
	array_list[index]=0
	
