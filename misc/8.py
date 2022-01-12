a = [1, 2]
for i in range(2, 1002):
	a.append((a[i - 1] + (a[i - 2] * 2)) // 2)
print(a[:10])
print(a[100])
print(a[1000])