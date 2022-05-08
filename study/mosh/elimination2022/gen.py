from os import popen

def gen(x, y):
    with open("test.in", "w") as f:
        f.write("10 " + str(x) + " 10 " + str(y) + "\n")
        f.write("1\n10\n1 1 0 1 0 0 1 0 1 0\n1 0 0 1 1 1 0 1 0 1\n1 0 1 0 1 1 1 1 0 0\n0 1 0 1 1 0 1 0 1 0\n0 1 0 1 0 0 0 0 1 0\n1 0 1 0 1 1 0 1 0 1\n1 0 1 0 1 1 0 1 0 1\n0 1 0 0 0 0 1 0 1 0\n1 0 1 0 1 1 0 1 0 1\n1 0 1 0 1 0 0 0 0 1")

for i in range(10):
    # for j in range(10):
    gen(0,i)

    sol = popen("./sol < test.in").read()

    print("--- CASE", str(0), str(i), "---")
    print(sol)
