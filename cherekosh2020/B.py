a, b = map(int, input().split())
m = int(input())
for i in range(m):
	ai = int(input())
	if ((ai % (a + b)) >= min(a, b)): print(1)
	else: print(2) 