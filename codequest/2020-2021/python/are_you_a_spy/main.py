n = int(input())
punc = '''!()-[]{};:'"\,<>./?@#$%^&*_~'''
for i in range(n):
    s1, s2 = [i.lower().replace(" ", "") for i in input().split("|")]
    for c in s1:
        if c in punc:
            s1 = s1.replace(c, "")
    for c in s2:
        if c in punc:
            s2 = s2.replace(c, "")
    p=""
    for char in s1:
        if char not in p:
            p+=char
    q=""
    for char in s2:
        if char not in q:
            q+=char
    
    p = sorted(p)
    q = sorted(q)
    
    for i in p:
        if i in q:
            q.remove(i)
    print("That's my secret contact!" if q == [] else "You're not a secret agent!")
  
    