import numpy as np

np.random.seed(1)
N = 2**16
a = np.random.randint(1, 7, (N))


def calc(m):
    b = int(N / m)
    z = np.zeros(b)
    for i in range(b):
        z[i] = np.average(a[i * m:(i + 1) * m])
    z = 1.0 / z
    ave = np.average(z)
    err = np.std(z) / np.sqrt(len(z))
    print(f"{m} {ave} {err}")


for m in [4, 8, 16, 32, 64, 128]:
    calc(m)
