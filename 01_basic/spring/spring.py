h = 0.1
T = 10
x = 0.0
k = 1.0
m = 1.0
v = 1.0
steps = int(T/h)
for i in range(steps):
    v -= x * h
    x += v * h
    t = i * h
    print(f"{t} {x}")
