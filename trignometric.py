f=[1]*10
p="{0:.3f}".format
for b in range(1,10):
	f[b] = f[b-1]*b
for i in range(input()):
	x=float(input())
	s=c=v=0
	y=m=1
	while(v<10):
		o=(m)*y/f[v]
		if(v%2==0):
			c+=o
		else:
			s+=o
			m*=-1
		y*=x
		v+=1
	print p(s),'\n',p(c)