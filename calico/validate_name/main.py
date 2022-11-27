def is_valid(s) -> bool:
    if len(s) >= 50:
        return False
    words = s.split()
    BANNED = {"california", "cal", "berkeley"}
    if words[0].lower() in BANNED:
        return False
    return True


def main():
    n = int(input())
    for i in range(n):
        year = int(input())
        name = input().strip()
        if year <= 2010:
            print("VALID" if len(name) <= 50 else "INVALID")
            continue
        print("VALID" if is_valid(name) else "INVALID")


if __name__ == "__main__":
    main()
