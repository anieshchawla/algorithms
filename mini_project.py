def merge(line):
    """
    Function that merges a single row or column in 2048.
    """
    # replace with your code
    temp=[]
    for x in line:
    	if(x>0):
    		temp.append(x)
    add=[]
    if (temp ==[]):
    	return line
    else :
    	y=1;
    	while(y<len(temp)):
    		if(temp[y]==temp[y-1]):
    			add.append(temp[y]+temp[y-1])
    			y+=1
    		else:
    			add.append(temp[y])
    			y+=1
    	if(len(add)!=len(line)):
    		for k in range((len(line)- len(add))):
    			add.append(0)

    return add

list_of = [8, 16, 16, 8]
print merge(list_of)