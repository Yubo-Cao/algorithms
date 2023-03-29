from decimal import *

for i in range(int(input())):
    amount = input()
    amt = Decimal(amount[1:])
    numQ, numD, numN, numP = 0, 0, 0, 0
    while (amt >= 0.25):
        amt -= Decimal(0.25)
        numQ += 1
    while (amt >= 0.10):
        amt -= Decimal(0.10)
        numD += 1
    while (amt >= 0.05):
        amt -= Decimal(0.05)
        numN += 1
    while (amt > 0):
        amt -= Decimal(0.01)
        numP += 1
    print(amount)
    print("Quarters="+str(numQ))
    print("Dimes="+str(numD))
    print("Nickels="+str(numN))
    print("Pennies="+str(numP))