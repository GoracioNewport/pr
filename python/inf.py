for n in range(1, 1000):
	f = False
	for x in range(1, 200):
		for y in range(1, 200):
			if not not not not (((y + 4 * x) < n) and ((x + 3 * y) > 100) and (5 * x + 2 * y) > 150): f = True
	print(n, end=' ')
	if (f): print("---")
	else: print("OK")