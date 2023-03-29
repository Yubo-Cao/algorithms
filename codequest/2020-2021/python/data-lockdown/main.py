for i in range(int(input())):
    for n in range(int(input())):
        url, data = input().split()
        data = int(data)
        if (url.endswith(".lmco.com")):
            continue;
        else:
            if data > 1000:
                print(url, data)