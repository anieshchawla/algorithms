# b = [(lambda b: (lambda a, b: a(a, b))(lambda a, b: b*a(a, b-1) if b > 0 else 1,b))(num) for num in range(1,10)]
fact=[1]*9
for b in range(1,10):
	fact[b] = fact[b-1]*b

for i in range(int(raw_input())):
	