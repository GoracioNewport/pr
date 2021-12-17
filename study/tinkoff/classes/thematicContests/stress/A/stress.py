from os import popen
from random import randint

def gen():
    with open('test.in', 'w') as f:
        t = randint(1, 1000000)
        f.write(str(t) + '\n')
        for _ in range(t):
            f.write(str(randint(1, 9000000000000000000)) + '\n')

while(True):
    gen()
    smart = popen('./smart < test.in').read()
    stupid = popen('./stupid < test.in').read()

    if (smart != stupid):
        print(smart, stupid)
        break
