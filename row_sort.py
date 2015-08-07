nums=raw_input().split(" ")
n=int(nums[0])
m=int(nums[1])
element=[]
for x in range(n):
    element.append(map(int,raw_input().split(" ")))
k=int(input())
print element
element.sort(key=lambda x: x[k])
for y in element:
	for z in y:
		print z,
	print " "
