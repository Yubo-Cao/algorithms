def fib(n):
    f = [0, 1]
    for i in range(2, n+1):
        f.append(f[i-1] + f[i-2])
    return f[n]

for i in range(int(input())):
    n = int(input())
    print(str(n) + " = " + str(fib(n-1))) 