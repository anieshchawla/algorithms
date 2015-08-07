import collections
# A = collections.OrderedDict()
# B = collections.OrderedDict()
A=dict()
B=dict()
A['a'] ="A"
A["b"] ="B"
A["c"] = "C"

B["c"] = "C"
B["b"] ="B"
B['a'] ="A"

print (A==B)