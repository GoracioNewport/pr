from random import randint
from os import popen
from math import sqrt

# t = 1


def isPrime(x):
    for i in range(2, int(sqrt(x)) + 1):
        if (x % i == 0): return False
    return True

def gen():
    with open("test.in", "w") as f:
        x = 4
        while(not isPrime(x)): x = randint(1, 100000000)
        f.write(str(x))

while(True):
    gen()
    smart = popen("./smart < test.in").read()
    stupid = popen("./stupid < test.in").read()

    if (smart != stupid):
        print(smart)
        print(stupid)
        break
    # else:
        # print("TEST PASSED")
