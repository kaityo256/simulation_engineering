t = 0
h = 0.05
p = 1.0
q = 0.0
T = 1000

for _ in range(T):
    print(f"{t} {p} {q}")
    t = t + h
    dp = - q * h
    dq = p * h
    p += dp
    q += dq
