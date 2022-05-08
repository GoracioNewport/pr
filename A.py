t = int(input())
for k in range(t):
	x, y = map(int, input().split())
	ans = x + y
	if (abs(x - y) > 2): ans += (abs(x - y) - 1)
	print(ans)