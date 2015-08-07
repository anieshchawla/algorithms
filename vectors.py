import math
def cross(a, b):
    c = [a[1]*b[2] - a[2]*b[1],
         a[2]*b[0] - a[0]*b[2],
         a[0]*b[1] - a[1]*b[0]]

    return c
def dot(a,b):
	ans=0
	for i in range(len(a)):
		ans+=a[i]*b[i]
	return ans
def mod_num(a):
	a=dot(a,a)
	return math.sqrt(a)
def diff(a,b):
	ans=[]
	for i in range(len(a)):
		ans.append(b[i]-a[i])
	return ans

a = map(float, raw_input().split(" "))
b = map(float, raw_input().split(" "))
c = map(float, raw_input().split(" "))
d = map(float, raw_input().split(" "))

ab = diff(a,b)
bc = diff(b,c)
cd = diff(c,d)

X = cross(ab,bc)
Y = cross(bc,cd)
ans = math.acos(dot(X,Y)/(mod_num(X)*mod_num(Y)))
print '%.2f' %math.degrees(ans)