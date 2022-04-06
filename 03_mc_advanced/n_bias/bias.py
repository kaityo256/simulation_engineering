import numpy as np

N = 2**16

a = 1.0 / np.random.randint(1, 6, (N))
def calc(m):
    z = np.zeros(m)
    for i in range(m):
        z[i] = np.average(a[i*m:(i+1)*m])
    ave = np.average(z)
    err = np.std(z)/np.sqrt(m)
    print(f"{m} {ave} {err}")


for m in [4,8,16,32,64, 128]:
    calc(m)


