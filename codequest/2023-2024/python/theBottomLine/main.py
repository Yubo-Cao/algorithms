"""3
22 9
6 14
12 12

"""
"""
Cassowary Craft sold 13 more aircraft
Lead Balloons Ltd sold 8 more aircraft
Cassowary Craft and Lead Balloons Ltd sold the same number of aircraft

"""

for i in range(int(input())):
    a, b = map(int, input().split())
    if a > b:
        print("Cassowary Craft sold {} more aircraft".format(a - b))
    elif a < b:
        print("Lead Balloons Ltd sold {} more aircraft".format(b - a))
    else:
        print("Cassowary Craft and Lead Balloons Ltd sold the same number of aircraft")