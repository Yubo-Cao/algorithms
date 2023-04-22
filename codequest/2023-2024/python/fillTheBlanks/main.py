import re

for _ in range(int(input())):
    a, b = map(int, input().split())
    vars = dict([input().split(": ", 1) for _ in range(a)])
    tmpl = "\n".join([input() for _ in range(b)])
    # vars resovle with re
    var = re.compile(r"\[(.*?)\]")
    for potential_sub in var.findall(tmpl):
        if potential_sub in vars:
            tmpl = tmpl.replace(f"[{potential_sub}]", vars[potential_sub])

    print(tmpl)