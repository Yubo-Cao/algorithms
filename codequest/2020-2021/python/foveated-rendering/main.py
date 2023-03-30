for i in range(int(input())):
    arr = [[10 for x in range(20)] for y in range(20)]
    x, y = [int(x) for x in input().split()]
    arr[x][y] = 100
    if (x == 0 and y == 0):
        arr[1][0], arr[0][1], arr[1][1] = [50]*3
        arr[2][0], arr[2][1], arr[0][2], arr[1][2], arr[2][2] = [25]*5
    elif (x == 0 and y == 19):
        arr[0][18], arr[1][18], arr[1][19] = [50]*3
        arr[0][17], arr[1][17], arr[2][17], arr[2][18], arr[2][19] = [25]*5
    elif (x == 19 and y == 0):
        arr[18][0], arr[18][1], arr[19][1] = [50]*3
        arr[17][0], arr[17][1], arr[17][2], arr[18][2], arr[19][2] = [25]*5
    elif (x == 19 and y == 19):
        arr[18][19], arr[18][18], arr[19][18] = [50]*3
        arr[17][17], arr[17][18], arr[17][19], arr[18][17], arr[19][17] = [25]*5
    else:
        arr[x+1][y], arr[x][y+1], arr[x+1][y+1], arr[x-1][y], arr[x][y-1], arr[x-1][y-1], arr[x+1][y-1], arr[x-1][y+1] = [50]*8
        arr[x-2][y-2], arr[x-1][y-2], arr[x][y-2], arr[x+1][y-2], arr[x+2][y-2], arr[x-2][y-1], arr[x+2][y-1], arr[x-2][y], arr[x+2][y], arr[x-2][y+1], arr[x+2][y+1], arr[x-2][y+2], arr[x-1][y+2], arr[x][y+2], arr[x+1][y+2], arr[x+2][y+2] = [25]*16
    for r in range(len(arr)):
        print(*arr[r], sep=" ")