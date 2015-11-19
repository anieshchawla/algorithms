from collections import OrderedDict
string = raw_input()
chunk = int(input())
string_arr = [string[i:i+chunk] for i in xrange(0,len(string),chunk)]
for chnge_string in string_arr:
	print "".join(OrderedDict.fromkeys(chnge_string))