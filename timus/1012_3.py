n = int(input())
k = int(input())
m = int(input())

if (n == 1):
	print((k - 1) % m)
elif (n == 2):
	print(((k - 1) * (k - 1) + (k - 1)) % m) 
else:

	pprev = [0, k - 1]
	prev = [(k - 1), (k - 1) * (k - 1)]
	cur = [0,0]

	for i in range(2, n):
		
		cur = [prev[1] + prev[0] - pprev[1], (prev[1] + prev[0]) * (k - 1)]
		pprev = prev
		prev = cur



	print((cur[0] + cur[1]) % m)