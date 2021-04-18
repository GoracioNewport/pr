n = int(input())
k = int(input())

dp = [[0] * 2 for i in range((n + 2))]

dp[0][0] = 0;
dp[0][1] = k - 1;
dp[1][0] = dp[0][1];
dp[1][1] = dp[0][1] * (k - 1);

for i in range(2, n):
	dp[i][0] = dp[i - 1][1] + dp[i - 1][0] - dp[i - 2][1]
	dp[i][1] = (dp[i - 1][1] + dp[i - 1][0]) * (k - 1);
print(dp[n - 1][0] + dp[n - 1][1])

