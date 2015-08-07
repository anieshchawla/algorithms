"""
This is the function to take a string of number as input
and it will then gives the output of the required answer of 
2048
"""
def merge(line):
    """merge Function is one  which merges a single row or column in 2048.
     finding the non empty numbers and storing in temp
     """
    temp=[]
    for _non_zero_nos in line:
        if(_non_zero_nos>0):
            temp.append(_non_zero_nos)
    #the addition list of numbers after getting the temp
    _add_list=[]
    if (len(temp) ==0):
        return line
    else:
        _iterator=1;
        _last_elem=0;
        _add_list.append(temp[0])
        while(_iterator<len(temp)):
            if(_add_list[_last_elem] == temp[_iterator]):
                _add_list[_last_elem]+=temp[_iterator]
                if(_iterator<=(len(temp)-2)):
                    _add_list.append(temp[_iterator+1])
                    _iterator+=1
                    _last_elem+=1
            else:
                _add_list.append(temp[_iterator])
                _last_elem+=1
            _iterator+=1
        # #padding it with zeros to make the list complete
        if(len(_add_list)!=len(line)):
            while((len(line)- len(_add_list))!=0):
                _add_list.append(0)
    return _add_list
# print merge([2, 0])
# print merge([4])
# print merge([2, 0, 2, 4])
# print merge([0, 0, 2, 2])
# print merge([8, 8, 8, 2])
# print merge([2, 2, 2, 2, 2]) #should return [4, 4, 2, 0, 0]
# print merge([8, 16, 16, 8]) #should return [8, 32, 8, 0]
