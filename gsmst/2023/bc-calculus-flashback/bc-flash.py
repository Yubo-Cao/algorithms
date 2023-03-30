import math

n, h, x, y = map(float, input().split())
while n:
    y += h * math.sin(x) * math.e**x
    x += h
    n -= 1

print(round(y, 2))
