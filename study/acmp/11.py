l = input().split()
k = int(l[0])
n = int(l[1])
dp = list()
dp.append(1)
for i in range(1, k):
	s = 0
	for j in range(i):
		s += dp[j]
	dp.append(s)
for i in range(k, n + 1):
	s = 0
	for j in range(i - k, i):
		s += dp[j]
	dp.append(s)
# for i in dp: print(i, end=' ')
# print()
print(dp[n])