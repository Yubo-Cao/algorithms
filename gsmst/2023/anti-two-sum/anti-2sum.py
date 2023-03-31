t = int(input())
xs = list(map(int, input().split()))

for idx, i in enumerate(xs):
    for j in xs[:idx] + xs[idx + 1 :]:
        if i + j == t:
            break
    else:
        print(idx)
