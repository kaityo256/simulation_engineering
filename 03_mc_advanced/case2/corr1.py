import numpy as np

np.random.seed(1)

N = 2048
d = np.random.random(N)
for i in range(4, 12):
    n = 2**i
    dd = d[:n]
    ave = np.average(dd)
    err = np.std(dd)/np.sqrt(n)
    print(f"{n} {ave} {err}")
