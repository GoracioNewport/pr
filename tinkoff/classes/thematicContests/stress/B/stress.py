from os import popen, system
from random import randint

def gen():
    n = randint(1, 10)
    cnt = 0

    left = 100000

    ans = []

    for i in range(n):
        if (left <= 1): break

        li = randint(0, 2)
        if (li > left): li = left
        ansP = []
        for _ in range(li): ansP.append(randint(-100, 100))
        ans.append(ansP)
        cnt += 1
        left -= li

    with open('test.in', 'w') as f:
        f.write(str(len(ans)) + '\n')
        for i in ans:
            f.write(str(len(i)))
            for j in i:
                f.write(' ' + str(j))
            f.write('\n')

while(True):
    gen()

    if (system('./smart < test.in > test.out') != 0):
        print("RE")
        break
