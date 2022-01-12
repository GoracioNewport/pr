import turtle
f = open('numbers.txt', 'r')
z = f.read().split()
# print(z)

t = turtle.Turtle()
t.speed(0)

for i in range(len(z) // 2):
	# print(z[2 * i], z[2 * i + 1])
	t.goto(int(z[i]) - 500, int(z[i + 1]) - 400)

turtle.done()