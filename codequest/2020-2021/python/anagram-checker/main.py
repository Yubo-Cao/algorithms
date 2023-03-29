n = int(input())
for i in range(n):
    inp = input()
    w1, w2 = inp.split("|")
    if (w1 == w2):
        print(inp + " = " + "NOT AN ANAGRAM")
    elif (sorted(w1) == sorted(w2)):
        print(inp + " = " + "ANAGRAM")
    else:
        print(inp + " = " + "NOT AN ANAGRAM")
        
    