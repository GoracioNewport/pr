x1, x2 = map(int, input().split(':'))
y1, y2 = map(int, input().split(':'))
g = int(input()) # - 1 - Первая игра для первой команды дома, 2 - в гостях

ans = 0
win = False

while (not win):
	if ((x1 + y1 > x2 + y2) or ((x1 + y1 == x2 + y2) and (((g == 1) and (y1 > x2)) or ((g == 2) and (x1 > y2))))): break
	y1 += 1
	ans += 1
print(ans)