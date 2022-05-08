from random import randint
from os import popen

def gen():
    with open("test.in", "w") as f:
        f.write("1\n")
        n = randint(1, 10000)
        f.write(str(n) + "\n")

        for _ in range(n): f.write(str(randint(1, 1000)) + " ")

while (True):
    gen()
    slow = popen("./slow < test.in").read()
    fast = popen("./fast < test.in").read()

    if (slow != fast):
        break
    else: print("OK")
