for _ in range(int(input())):
    l = [[10 for _ in range(20)] for _ in range(20)]
    x, y = map(int, input().split())
    s = lambda x, y, r, v: [
        row.__setitem__(
            slice(max(y - r, 0), min(y + r + 1, len(row))),
            [v] * (min(y + r + 1, len(row)) - max(y - r, 0)),
        )
        for row in l[max(x - r, 0) : min(x + r + 1, len(l))]
    ]
    s(x, y, 2, 25), s(x, y, 1, 50), s(x, y, 0, 100)
    print("\n".join(" ".join(map(str, row)) for row in l))