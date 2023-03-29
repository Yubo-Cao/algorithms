n = int(input())
for i in range(n):
    l = input().translate(str.maketrans("ATCG", "0011"))
    print("".join(chr(int(l[n : n + 7], 2)) for n in range(0, len(l), 7)))
