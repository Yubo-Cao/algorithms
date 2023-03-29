for i in range(int(input())):
    n = int(input())
    if (n == 1):
        print("1")
        continue
    sensors = sorted([int(x) for x in input().split()])
    for x in range(1, n+1):
        if x not in sensors:
            print(x)
            continue