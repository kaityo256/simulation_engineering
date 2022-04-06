import numpy as np

np.random.seed(1)
gamma = 0.1
v = 0.0

for j in range(1000):
    v += np.random.randn()*0.1
    v -= gamma * v
    print(f"{j} {v}")
