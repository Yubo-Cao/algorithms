for i in range(int(input())):
    lastYear = input().split(",")
    thisYear = input().split(",")
    thisYearNotLastYear = []
    lastYearNotThisYear = []
    bothYears = []
    for item in thisYear:
        if item not in lastYear:
            thisYearNotLastYear.append(item)
    for item in lastYear:
        if item not in thisYear:
            lastYearNotThisYear.append(item)
    for item in thisYear:
        if item in lastYear:
            bothYears.append(item)
    
    print(*sorted(lastYearNotThisYear), sep=",")
    print(*sorted(bothYears), sep=",")
    print(*sorted(thisYearNotLastYear), sep=",")