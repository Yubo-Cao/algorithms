for i in range(int(input())):
    temp, water, field, eccentricity = input().split()
    temp = float(temp)
    eccentricity = float(eccentricity)
    if (temp > 100):
        print("The planet is too hot.")
        continue
    elif (temp < 0):
        print("The planet is too cold.")
        continue
    elif (water == "false"):
        print("The planet has no water.")
        continue
    elif (field == "false"):
        print("The planet has no magnetic field.")
        continue
    elif (eccentricity > 0.6):
        print("The planet's orbit is not ideal.")
        continue
    else:
        print("The planet is habitable.")