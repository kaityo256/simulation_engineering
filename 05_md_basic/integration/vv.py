t = 0
h = 0.05
p = 1.0
q = 0.0
T = 1000


for _ in range(T):
    print(f"{t} {p} {q}")
    t = t + h
    ft = -q
    q += p * h - q * h**2 * 0.5
    ft2 = -q
    p += (ft2 + ft) * h * 0.5
