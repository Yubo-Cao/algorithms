import re

n = int(input())
for i in range(n):
    string = input()
    print(re.sub('[^A-Za-z0-9 ]+', '', string))