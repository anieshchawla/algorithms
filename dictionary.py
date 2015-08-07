'''Thing to do in this dictionary:
1. Make a better data structure(if possible) to store the entries
2. associate timers with each entry, after expiry of that timer, the entry should be deleted
3. make the size of the dictionary to store a maximum of 1000 entries, and based on FIFO we should keep the entries'''
from expiringdict import ExpiringDict
content_dictionary = ExpiringDict(max_len=100,max_age_seconds=2)
def add(content,ip,port):
	index=0
	if(content not in content_dictionary):
		content_dictionary[content] = ([{"ipaddr":ip,"port":port}])
	else:
		index=len(content_dictionary[content])
		content_dictionary[content].append({"ipaddr":ip,"port":port})
def check(content):
	'''Make a better algo for checking the dictionary, as this will be time consuming'''
	if(content in content_dictionary):
		return True
	else:
		return False
def get():
	return content_dictionary
def delete(key,index):
	print "inside"
	if(len(content_dictionary[key])>1):
		content_dictionary[key].pop(index)
	else:
		del content_dictionary[key]
