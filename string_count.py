string = raw_input()
ans=1
count=1
for x in range(1,len(string)):
    if(string[x]==string[x-1]):
    	print count," count"
        count+=1
    else:
         ans*=count
         count=1
if(count==len(string)):
	ans=1
else:
	ans*=count
ans=ans%1000
print ans