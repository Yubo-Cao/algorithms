sum = 0 
c = 0
for i in range( int(input())):
    str = input()
    grade = int(input())
    if ("AP" in str):
        grade += 10
    sum += grade
    c += 1
print(round(sum / c))