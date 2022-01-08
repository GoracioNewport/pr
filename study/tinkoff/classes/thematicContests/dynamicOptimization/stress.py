from random import randint
from os import popen

def gen():
	with open('test.in', "w") as f:
		n = randint(1, 10)
		f.write(str(n) + '\n')
		for _ in range(n): f.write(str(randint(1, 10)) + ' ' + str(randint(1, 10)) + '\n')

while True:
	gen()
	smart = popen("./a.out < test.in").read()
	stupid = popen("./slow < test.in").read()

	if (smart != stupid):
		break