ans = [-1 for _ in range(100)]

def f(n):
	if (ans[n] == -1):

		cnt = 1
		if (n >= 1):
			cnt += 1
			cnt += f(n - 1)
			cnt += f(n - 2)
			cnt += 1
		ans[n] = cnt

	return ans[n]

print(f(35))