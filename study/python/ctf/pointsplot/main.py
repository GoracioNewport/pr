# import numpy as np
import matplotlib.pyplot as plt

f = open("cords.txt", 'r')
z = f.read().split('\n')
# print(z)

x = list()
y = list()

for _ in z:
    r = _.split()
    # print(r)
    x.append(int(r[0]) // 10)
    y.append(int(r[1]))
    # print(r[0], r[1])

# print(x)
# print(y)

plt.scatter(x, y, s = 3)
# plt.xticks(range(1,5))
plt.show()