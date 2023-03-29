from decimal import Decimal

for i in range(int(input())):
    amount = Decimal((raw := input())[1:])
    print(raw)
    coins = [
        (Decimal("0.25"), "Quarters"),
        (Decimal("0.10"), "Dimes"),
        (Decimal("0.05"), "Nickels"),
        (Decimal("0.01"), "Pennies"),
    ]
    for coin in coins:
        print(coin[1] + "=" + str(int(amount / coin[0])))
        amount %= coin[0]
