n = int(input())

from math import sqrt
# from random import random

# globCnt = 0
# sirCnt = 0

# for i in range(n):
# 	x = (random() - .5) * 2
# 	y = (random() - .5) * 2

# 	if (x * x + y * y <= 1): sirCnt += 1
# 	globCnt += 1

# print(sirCnt / globCnt * 4)


s = 0

for i in range(1,n + 1):
	s += 1 / (i * i)

print(sqrt(s * 6))