from os import popen
n = int(input())

dp = [[0] * (n + 1) for _ in range((n + 1))]

for i in range(1, n + 1):
	for j in range(1, i + 1):
		if (i * j > n): break
		with open('test.in', 'w') as f:
			f.write(str(i) + ' ' + str(j))
		ans = popen('./a.out < test.in').read()
		dp[i][j] = ans
		dp[j][i] = ans

with open('gen.txt', 'w') as f:
	f.write("{")
	for i in range(0, n + 1):
		f.write("{ ")
		for j in range(0, n + 1):
			if (j != 0): f.write(", ")
			f.write("{" + str(dp[i][j]) + "}")
		f.write("}" + '\n')
	f.write("}")