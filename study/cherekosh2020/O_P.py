n, k = map(int, input().split())
d = (n // k)
e = 0
if (k % 2 == 0):
	e = n // k
	if (((n // k) * k) + (k // 2) <= n): e += 1
print(d * d * d + e * e * e)