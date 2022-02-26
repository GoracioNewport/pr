t = int(input())
for _ in range(t):
    n, k, x = map(int, input().split())
    x -= 1
    s = input()
    zip = list()
    buf = 0



    for i in s:
        if (i == '*'): buf += 1
        else:
            if (buf > 0): zip.append(['*', buf])
            buf = 0
            zip.append(['a', 1])

    if (buf > 0): zip.append(['*', buf])

    pos = [1]
    zip = zip[::-1]

    for i in zip:
        if (i[0] == 'a'): continue
        else:
            y = pos[-1] * (i[1] * k + 1)
            y = min(y, 2e19)

            pos.append(y)

    pos = pos[::-1]
    zip = zip[::-1]

    ans = ""
    ind = 0

    for i in zip:


        if (i[0] == 'a'): ans += 'a'
        else:

            q = ""
            if (pos[ind + 1] != 2e19):
                for j in range(x // pos[ind + 1]): q += 'b'
                ans += q
                x %= pos[ind + 1]
            ind += 1

    print(ans)
