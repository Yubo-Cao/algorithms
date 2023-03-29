import re


def solve():
    code = {**dict([input().split(" ", 1) for _ in range(26)]), " ": " "}
    rev = {v: k for k, v in code.items()}

    enc = "   ".join(code[c] for c in input())
    dec = " ".join(
        "".join(rev[c] for c in w.split("   "))
        for w in re.split(
            r"\s{7,}",
            input(),
        )
    )

    print(enc)
    print(dec)


[solve() for _ in range(int(input()))]
