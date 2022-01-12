from os import popen
from random import randint

def gen(fileName, maxN, maxA):
    with open(fileName, 'w') as f:
        # n = randint(1, maxN)
        n = 200000
        f.write(str(n) + '\n')
        for _ in range(n): f.write(str(randint(0, maxA)) + ' ')


startTest, finishTest, maxN, maxA = map(int, input().split())

for i in range(startTest, finishTest + 1):
    fileName = './tests/' + str(i).zfill(3)
    gen(fileName + '.dat', maxN, maxA)

    ans = popen('./smart < ' + fileName + '.dat').read()
    with open(fileName + '.ans', 'w') as f:
        f.write(ans)

    print("[TESTGEN] Test №" + str(i) + " competed")
