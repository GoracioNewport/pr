def ok(hc, dc, hm, dm):
    turnCnt = hc // dm
    if (hc % dm == 0): turnCnt -= 1

    turnCnt += 1
    hm -= turnCnt * dc

    return (hm <= 0)

t = int(input())
for _ in range(t):
    hc, dc = map(int, input().split())
    hm, dm = map(int, input().split())
    k, w, a = map(int, input().split())
    can = False
    for x in range(k + 1):
        y = k - x;
        if (ok(hc + x * a, dc + y * w, hm, dm)): can = True

    if (can): print("YES")
    else: print("NO")
