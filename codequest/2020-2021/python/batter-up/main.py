n = int(input())
for i in range(n):
    name, rest = input().split(":")
    bats = [bat for bat in rest.split(",") if bat != "BB"]
    sum = 0
    for j in range(len(bats)):
        sum += (int(bats[j][0]) if (bats[j][0] in "123") else 0)
        sum += (4 if (bats[j][0] == "H") else 0)
    result = (f'{sum/len(bats):.3f}' if len(bats) > 0 else "0.000")
    print(name + "=" + result)
        
            
