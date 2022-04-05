import random
import numpy as np
import math


def calc(n):
    a = [random.randint(1, 6) for _ in range(n)]
    na = np.array(a)
    ave = np.average(na)
    std = np.std(na) / math.sqrt(n)
    return ave, std


def calc_inv(n):
    a = [1.0 / random.randint(1, 6) for _ in range(n)]
    na = np.array(a)
    ave = np.average(na)
    std = np.std(na) / math.sqrt(n)
    return ave, std


def normal(f):
    for i in range(10):
        ave, std = f(10)
        print(f"{i} {ave} {std}")


normal(calc_inv)
