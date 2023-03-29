n = int(input())
for i in range(n):
    numAsteroids = int(input())
    L = []
    for j in range(numAsteroids):
        (x, y) = map(int, input().split())
        L.append((x, y))
    L.sort(key=lambda x: x[0]**2 + x[1]**2)
    # Fix this line:  
    for (x, y) in L:
        print(x, y)   