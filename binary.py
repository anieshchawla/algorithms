T= int(input())
for x in range(T):
	n,k=raw_input().split()
	n=int(n)
	k=int(k)
	k+=1
	input_string = raw_input()
	#print input_string
	count,flip_count,char = 1,0,0
	while char < len(input_string):
		if(char>0):
			if(input_string[char]==input_string[char-1]):
				count+=1
			else:
				count=1
		if(count%k==0):
			if(k==2):
				flip_count+=1
				if(input_string[char]=="0"):
					input_string=input_string[:char]+ "1"+ input_string[char+1:]
				else:
					input_string=input_string[:char]+ "0"+ input_string[char+1:]
			else:
				char+=1
				while ((input_string[char]==input_string[char-1]) and char<len(input_string)):
					count+=1
					char+=1
				while (count>0):
					flip_count+=1
					if(count>k):
						if(input_string[char-count+k-1]=="0"):
							input_string=input_string[:char-count+k-1]+ "1"+ input_string[char-count+k:]
						else:
							input_string=input_string[:char-count+k-1]+ "0"+ input_string[char-count+k:]
					elif(count==k):
						if(input_string[char-count+k-1]=="0"):
							input_string=input_string[:char-count+k-2]+ "1"+ input_string[char-count+k-1:]
						else:
							input_string=input_string[:char-count+k-2]+ "0"+ input_string[char+-count+k-1:]
					count-=k
			count = 1
		char+=1	
	print flip_count
	print input_string

