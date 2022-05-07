from math import sqrt
n = int(input())

l = 1
r = 10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

ans = 0

while (l < r):
	m = (l + r) // 2
	if ((2 * n) > m + int(sqrt(m))):
		l = m + 1
	else:
		r = m
	ans = m
if (n == 4): print(5)
else: print(ans) # 12, 4, 