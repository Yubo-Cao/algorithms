for i in range(int(input())):
    s, l, t = map(int, input().split())
    print("true" if l * 5 + s >= t and t % 5 <= s else "false")