from os import popen
from random import randint

def gen():
    with open("test.in", 'w') as f:

        n = randint(1, 10)
        f.write(str(n) + '\n')
        for i in range(n):
            x = randint(1, 100)
            f.write(str(x) + ' ')
while(True):
    gen()
    smart = popen("./smart < test.in").read()
    stupid = popen("./stupid < test.in").read()

    if (smart != stupid):
        # print("AAA")
        print(smart)
        print(stupid)
        break
