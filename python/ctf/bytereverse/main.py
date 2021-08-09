f = open('ReByte.mp4', 'r')
z = open('test.mp4', 'wb')
b = b'0'
cnt = 0
while(b and cnt < 5):
    b = f.read(49)
    y = list(b)
    # print(b, y)

    x = []

    k = ''
    for i in range(len(y)):
        if (y[i] == '\n'): continue

        if (i % 3 == 0): k += y[i]
        if (i % 3 == 1):
            k += y[i]
            x.append(k)
            k = ''
    print(x)

    for i in range(4):
        x[4 * i], x[4 * i + 3] = x[4 * i + 3], x[4 * i]
        x[4 * i], x[4 * i + 1] = x[4 * i + 1], x[4 * i]

    for _ in x:
        print(_, end=" ")
        _ = bytes.fromhex(_)
        print(_)
        z.write(_)

    print(x)

    # cnt += 1