import numpy as np

N = 1000
v = 0.0
gamma = 0.1
np.random.seed(1)

for j in range(10):
    d = np.zeros(N)
    for i in range(N):
        v += np.random.randn()*0.1
        v -= gamma * v
        d[i] = v
    ave = np.average(d)
    err = np.std(d) / np.sqrt(N)
    print(f"{(j+0.5)*N} {ave} {err}")
