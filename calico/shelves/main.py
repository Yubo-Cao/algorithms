def main():
    n = int(input())
    for i in range(n):
        n, b, w, d = [int(x) for x in input().split()]
        hs = [int(x) for x in input().split()]
        area = (sum(hs) + (n + 1) * b) * (b * 2 + w) - sum([h * w for h in hs])
        print(area * d)


if __name__ == "__main__":
    main()
