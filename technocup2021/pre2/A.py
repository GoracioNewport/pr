a, b, c = map(int, input().split())
if ((a * b == c) or (b * c == a) or (a * c == b)):
	print("Yes")
	if (a * b == c): print(a, b, c)
	elif (b * c == a): print(b, c, a)
	elif (c * a == b): print(c, a, b) 
else: print("No")