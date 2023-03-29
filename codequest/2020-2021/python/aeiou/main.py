n = int(input())
for i in range(n):
    str = input()
    count = len([char for char in str if char in "aeiouAEIOU"])
    print(count)