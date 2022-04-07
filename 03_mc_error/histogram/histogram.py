import itertools
import random

import numpy as np
from matplotlib import pyplot as plt

x = np.arange(1, 7)
y = [1.0/6.0] * 6

plt.bar(x, y)
plt.savefig("population.png")

plt.cla()

x = np.arange(1, 7)
p = itertools.product(x, x)
plt.hist([sum(t)/len(t) for t in p])
plt.savefig("n2.png")

plt.cla()

p = itertools.product(x, x, x, x)
plt.hist([sum(t)/len(t) for t in p])
plt.savefig("n4.png")

plt.cla()

n = 20000
a = []
np.random.seed(1)
for i in range(n):
    xi = np.average(np.random.randint(1, 7, 1000))
    a.append(xi)
plt.hist(a, bins=40)

plt.savefig("n1000.png")
