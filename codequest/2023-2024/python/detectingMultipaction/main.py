"""
3
.3 .61 .4 .15 .81 .47 .98
.2 .64 .7 .36 .63 .71 .09
.45 .53 .59 .13 .21 .78 .34 .78 .91
.87 .71 .32 .33 .58 .61 .79 .86 .62
.5 .71 .42 .36 .49 .82 .6 .21
.67 .41 .76 .83 .85 .12 .51 .92

"""

"""
2 multipaction events were detected at time indices: 1 4.
A multipaction event was detected at time index 5.
No multipaction events detected.
"""

"""
this subroutine and test it before it's loaded onto the satellites.If,for a given time index,both channels show a power reading between .6 and .85 of their maximum outputs (inclusive), that indicates an event which should be reported.
"""

for i in range(int(input())):
    l1 = [float(x) for x in input().split()]
    l2 = [float(x) for x in input().split()]
    result = []
    for i, (a, b) in enumerate(zip(l1, l2)):
        if 0.6 <= a <= 0.85 and 0.6 <= b <= 0.85:
            result.append(i)
    if result:
        if len(result) == 1:
            print(
                "A multipaction event was detected at time index {}.".format(result[0])
            )
        else:
            print(
                f'{len(result)} multipaction events were detected at time indices: {" ".join(map(str, result))}.'
            )
    else:
        print("No multipaction events detected.")
