n, k = map(int, input().split())
m = 0
if (k % 2 == 0):
	m = n // k
	if (((n // k) * k) + (k // 2) <= n): m += 1
ans = (m * m * m) + (n // k)
if (k % 3 == 0): ans = ans + (n // k)
print(ans)