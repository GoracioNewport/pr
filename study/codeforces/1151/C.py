mod = 1e9 + 7

def count(x):
    cntOdd = 0
    cntEven = 0

    i = 0

    while(cntOdd + cntEven < x):
        if (cntOdd + cntEven + (2 ** i) <= x):
            if (i % 2 == 0): cntOdd += (2 ** i)
            else: cntEven += (2 ** i)
            i += 1
        else:
            if (i % 2 == 0): cntOdd = x - cntEven
            else: cntEven = x - cntOdd
            break

    res1 = (cntOdd * cntOdd) % mod
    res2 = (cntEven * (cntEven + 1)) % mod
    return (res1 + res2) % mod

l, r = map(int, input().split())
print(int((count(r) - count(l - 1) + mod) % mod))