import numpy as np
from matplotlib import pyplot as plt


def calc(n):
    samples = 20000
    a = []
    np.random.seed(1)
    for _ in range(samples):
        xi = np.average(np.random.randint(1, 7, n))
        a.append(xi)
    return a


n10 = calc(10)
n100 = calc(100)
n1000 = calc(1000)
plt.hist(n10, bins=40, label="N=10")
plt.hist(n100, bins=40, label="N=100")
plt.hist(n1000, bins=40, label="N=1000")
plt.legend()
plt.savefig("compare.png")
