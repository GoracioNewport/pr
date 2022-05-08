n = int(input())
for i in range(n):
    x = i // ((n - i) * (n - i))

    l = i
    r = n

    while(l + 1 < r):
        m = (l + r) // 2
        if ((m / ((n - m) * (n - m))) == x): l = m
        else: r = m

    ans = ans + x * (l - i + 1)

    i = l

print(ans)