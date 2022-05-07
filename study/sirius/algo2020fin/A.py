n = int(input())
m = int(input())

a = m // (n - 1)

if (m % (n - 1) == 0):
	ma = a * n
	mi = ma - 1
	print(mi, ma)
else:
	print(m + a, m + a)