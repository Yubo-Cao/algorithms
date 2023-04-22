import itertools

for _ in range(int(input())):
    ip2macs = sorted([input().split() for _ in range(int(input()))], key=lambda x: x[0])
    ips = {}
    for ip, macs in itertools.groupby(ip2macs, key=lambda x: x[0]):
        macs = set([mac for _, mac in macs])
        ips[ip] = len(macs)
    sorted_ips = sorted(
        ips.items(), key=lambda x: [int(num) for num in x[0].split(".")]
    )
    for ip, count in sorted_ips:
        print(ip, count)
