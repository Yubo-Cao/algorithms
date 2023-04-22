"""
Your program will be given a list of words and the value of the letter A in cents. Each successive letter
in the alphabet will be worth one cent more, up to a maximum of 26 cents. The letter after the one
worth $0.26 will wrap back around to be worth a single cent. For example, if A is worth 5 cents, B will
be worth 6 cents, C will be worth 7 cents, and so on; V will be worth 26 cents, and W will be worth 1
cent.
For each word in the given list, you'll need to total up the values of the letters in that word to
determine their value. If the word is worth exactly $1.00, it's a winner!
"""

"""

2
1 4
FIRST
SECOND
THIRD
PROBLEMS
7 3
WINNER
CHICKEN
DINNER

"""

"""
WINNER 1: PROBLEMS
WINNER 7: DINNER
"""

for i in range(int(input())):
    a, w = map(int, input().split())

    def get_val(word):
        price = {}
        for k in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
            t = ord(k) - ord('A') + a
            if t >= 27:
                t -= 26
            price[k] = t
        return sum(price.get(k, 0) for k in word.upper())

    ans = ""
    for _ in range(w):
        word = input()
        if get_val(word) == 100:
            ans = word
    if ans:
        print(f"WINNER {a}: {ans}")
    else:
        print(f"No winner for {a} cents")