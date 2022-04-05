import random

random.seed(1)
pi = 0.0
N = 1000000
for _ in range(N):
    x = random.random()
    y = random.random()
    if x**2 + y**2 < 1.0:
        pi = pi + 1.0
pi = pi/N*4
print(pi)
