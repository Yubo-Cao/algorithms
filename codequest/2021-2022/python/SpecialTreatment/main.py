import re

n = int(input())
for i in range(n):
    print(re.sub('[^A-Za-z0-9 ]+', '', input()))