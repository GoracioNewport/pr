from random import randrange
from os import popen

def gen():
    with open("./test.in", "w") as f:
        n = randrange(1, 100)
        q = randrange(2, 100)

        f.write(str(n) + ' ' + str(q) + '\n')

        for _ in range(n):
            x = randrange(0, 1000)
            f.write(str(x) + ' ')

        f.write('\n')

        for _ in range(q):
            t = randrange(1, 3)
            f.write(str(t) + ' ')

            l = randrange(1, n + 1)
            r = randrange(1, n + 1)

            f.write(str(min(l, r)) + ' ' + str(max(l, r)) + ' ')

            if (t == 2): f.write(str(randrange(0, 1000)))

            f.write('\n')


while (True):
    gen()

    smart = popen("./smart < test.in").read()
    stupid = popen("./stupid < test.in").read()

    if (smart != stupid):
        break;
    # print("test passed", smart, stupid)
