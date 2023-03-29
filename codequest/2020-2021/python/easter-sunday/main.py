import math
for i in range(int(input())):
    year = int(input())
    a = year % 19
    b = year % 4
    c = year % 7
    k = math.floor(year/100)
    p = math.floor((13+8*k)/25)
    q = math.floor(k/4)
    m = (15-p+k-q)%30
    n = (4+k-q)%7
    d = (19*a+m)%30
    e = (2*b+4*c+6*d+n)%7
    f = (11*m + 11)%30
    date = 22 + d + e
    year = str(year)
    if (date <= 31):
        print(year + "/" + "03" + "/" + str(date))
        continue
    else:
        date -= 31
        answerPrefix = year + "/" + "04" + "/"
        if date == 25 and d == 28 and e == 6 and f < 19:
            print(answerPrefix + "18")
        elif date == 26 and d == 29 and e == 6:
            print(answerPrefix + "19")
        else:
            if (str(date) in ["1", "2", "3", "4", "5", "6", "7", "8", "9"]):
                answerPrefix += "0"
            print(answerPrefix + str(date))
    