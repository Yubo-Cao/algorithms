import re

for i in range(int(input())):
    illegal = [
        re.compile(r"'; .* --"),
        re.compile(r"' OR 1=1", re.IGNORECASE),
        re.compile(r"\$\{.*\}"),
        re.compile(r"\$\(.*\)"),
        re.compile(r"&& sudo"),
        re.compile(r"&& su -"),
        re.compile(r";;"),
        re.compile(r"<script", re.IGNORECASE),
        re.compile(r"%s"),
        re.compile(r"%x"),
        re.compile(r"%n"),
    ]
    line = input()
    if any(i.search(line) for i in illegal):
        print("REJECTED")
    else:
        print(line)
