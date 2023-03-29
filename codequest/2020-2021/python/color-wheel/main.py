for i in range(int(input())):
    betweenBR = ["red-violet", "violet", "blue-violet"]
    betweenRY = ["red-orange", "orange", "yellow-orange"]
    betweenBY = ["yellow-green", "green", "blue-green"]
    color = input()
    append = ''
    if (color in betweenBR):
        append = ', blue and red must be mixed.'
    elif (color in betweenRY):
        append = ', red and yellow must be mixed.'
    elif (color in betweenBY):
        append = ', blue and yellow must be mixed.'
    else:
        print("No colors need to be mixed to make " + color + ".")
        continue;
    print("In order to make " + color + append)
    