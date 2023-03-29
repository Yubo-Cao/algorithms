files = []
for i in range(int(input())):
    file = input()
    files.append(file[file.find("."):])
filesSet = []
[filesSet.append(x) for x in files if x not in filesSet]
for j in range(len(filesSet)):
    print(filesSet[j][1:], str(files.count(filesSet[j])))