import numpy as np

N = 10
np.random.seed(1)
for i in range(10):
    x = i + 0.5
    d = np.zeros(N)
    d += np.exp(-x/3)
    d += np.random.randn(N)*0.1
    y = np.average(d)
    e = np.std(d)
    print(f"{x} {y} {e}")
