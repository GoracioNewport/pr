from os import popen
from random import randint, choice

def gen():
    with open('test.in', 'w') as f:
        len = randint(1, 100)
        t = ""
        for _ in range(len): t += choice('abcdefghijklmnopqrstuvwxyz')
        f.write(t + '\n')


while(True):
    gen()

    smart = popen('./smart < test.in').read()
    stupid = popen('./stupid < test.in').read()
    if (smart != stupid):
        print("COUNTERTEST FOUND!")
        print(stupid)
        print(smart)
        break
    else:
        print("OK", stupid, smart)
