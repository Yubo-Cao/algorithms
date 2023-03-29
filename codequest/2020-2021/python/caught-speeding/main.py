for i in range(int(input())):
    speed, bday = input().split()
    speed = (int(speed)-5 if bday == "true" else int(speed)-0)
    print("no ticket" if speed <= 60 else ("small ticket" if speed >= 61 and speed <= 80 else "big ticket"))