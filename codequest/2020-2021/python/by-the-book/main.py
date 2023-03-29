import math
for i in range(int(input())):
    isbn = input()
    sum = 0
    for j in range(len(isbn)-1):
        sum += int(isbn[j])*(10-j)
    if (isbn[-1] == "X"):
        print("VALID" if math.ceil(sum/11)*11-sum == 10 else "INVALID")
    else:
        print("VALID" if math.ceil(sum/11)*11-sum == int(isbn[-1]) else "INVALID")
        
            
        