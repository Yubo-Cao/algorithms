l = []
s = input()
try:
    for c in s:
        if c in '({[':
            l += [c]
        else:
            assert {')': '(', '}': '{', ']': '['}[c] == l.pop()
except:
    print("INVALID")
    exit(0)
print("VALID" if not l else "INVALID")