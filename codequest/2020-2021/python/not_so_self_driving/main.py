n = int(input())
for i in range(n):
    speed, distance = map(float, input().split(":"))
    if (speed >= distance):
        print("SWERVE")
    elif (5*speed >= distance):
        print("BRAKE")
    else: 
        print("SAFE")