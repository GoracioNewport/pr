from random import randint
from os import popen

def gen():
	with open("./test.in", "w") as f:
		n = randint(1, 1000)
		k = randint(1, n)
		q = randint(1, 1000)
		f.write(str(n) + " " + str(k) + " " + str(q) + "\n")

		for _ in range(q):
			i = randint(1, n)
			x = randint(1, 100)
			f.write(str(i) + " " + str(x) + "\n")



while(True):
	gen()
	slow = popen("./slow < test.in").read()
	fast = popen("./fast < test.in").read()

	if (slow != fast):
		break