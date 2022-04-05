import numpy as np

np.random.seed(2)
for i in range(10):
    x = 1.0 + i * 0.1
    y = np.random.normal(loc=1.0+x*0.1, scale=0.1, size=(100))
    ave = np.average(y)
    std = np.std(y)/np.sqrt(len(y))
    print(f"{x} {ave} {std}")
