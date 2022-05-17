import numpy as np

N = 100

r = np.array(N)
v = np.array(N)

dt = 0.01

for i in range(N):
    r[i] = r[i] + v[i] * dt
