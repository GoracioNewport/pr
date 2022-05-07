WIN_CONDITION = 62

dp = dict()

def gameResult(x, y):
	if (x, y) in dp: 
		return dp[(x, y)]

	if x + y >= WIN_CONDITION:
		return 0


	nextMoves = [gameResult(x + 2, y), gameResult(x * 2, y), gameResult(x, y + 2), gameResult(x, y * 2)]

	loses = [i for i in nextMoves if i <= 0]

	if loses:
		res = -max(loses) + 1

	else:
		res = -max(nextMoves)

	dp[(x, y)] = res
	return res 


X = 7
for S in range(1, 55):
	print(X, S, gameResult(X, S))

