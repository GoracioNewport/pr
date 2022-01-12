# from math import abs

def calcOddTemp(m, h, c):
    M = 2 * m + 1
    temp = (((M // 2) * c) / M) + ((M // 2 + 1) * h / M);
    return temp

def calcOdd(h, c, t):
    l = 0
    r = 1000000

    while(l + 1 < r):
        m = (l + r) // 2
        temp = calcOddTemp(m, h, c)
        if (temp > t): l = m
        else: r = m

    return 2 * l + 1



t = int(input())
for _ in range(t):
    h, c, t = map(int, input().split(' '))

    evenAns = (h + c) / 2
    oddCnt = calcOdd(h,c,t)
    oddAns1 = ((oddCnt // 2) * c + (oddCnt // 2 + 1) * h) / oddCnt;
    oddCnt += 2
    oddAns2 = ((oddCnt // 2) * c + (oddCnt // 2 + 1) * h) / oddCnt;

    oddAns = 0
    if (abs(oddAns1 - t) > abs(oddAns2 - t)): oddAns = oddAns2;
    else:
        oddAns = oddAns1
        oddCnt -= 2

    oddCnt -= 2
    oddAns3 = ((oddCnt // 2) * c + (oddCnt // 2 + 1) * h) / oddCnt;
    if (abs(oddAns3 - t) < abs(oddAns - t)): oddAns = oddAns3
    else: oddCnt += 2


    if (abs(evenAns - t) > abs(oddAns - t)): print(oddCnt)
    else: print(2)