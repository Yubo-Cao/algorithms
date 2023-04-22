"""
1. Start with a value of 100,001
2. Add the 9-digit routing code to that value
3. Multiply the value by 50
4. For each of the 18 digits in the tracking code, from left to right, multiply the value by 10, ther
add that digit of the tracking code.
5. Convert the resulting value into a binary number
6. Add leading 0's to bring the binary value to a length of 96 bits
7. For each pair of bits in the binary value, from left to right, identify the resulting barcode
character as shown in the table below:

T -> 00
A -> 01
D -> 10
F -> 11
"""

"""
1
5
TDTADDAAFDDFAFFFFDDADFTAADATTFTAFTAAATADATFATAAA
DTTADAFFTTFTDFDTFAAADAAFATATAFFTFTFFDDDATTDTDFTA
TFAATTFTAFTAFAAADFDAAFAFFDDADDTTTFTTTDFFFFTAFDAA
AFDDFFDAFATATATTTFTFTTFFTAFFTFFAAAFADATTTAFTTTDA
TDTADDAAFDDFAFFFFFTFTTAAFFFFFADFTDTFFAADFTFDTTDA
"""

"""
Packages Sorted: 5
Standard Class: 1
First Class: 2
Priority Mail: 2
Most frequent mailer ID: 123456
Most frequent ZIP code: 20817
"""

from collections import Counter


def reverse_barcode(barcode: str):
    binary = "".join(
        [
            {"T": "00", "A": "01", "D": "10", "F": "11"}[barcode[i]]
            for i in range(0, len(barcode))
        ]
    )
    value = int(binary, 2)
    tracking = ""
    for i in range(18):
        digit = value % 10
        value //= 10
        tracking = str(digit) + tracking
        if i == 2:
            tracking = "0" + tracking
    routing = str(value // 50 - 100001)
    return tracking, routing


def parse_track(track: str):
    service_type = {
        "042": "STANDARD",
        "261": "STANDARD",
        "040": "FIRST",
        "300": "FIRST",
        "710": "PRIORITY",
        "712": "PRIORITY",
    }[track[:3]]
    mailer_id = track[3:9]
    return service_type, mailer_id


def parse_route(route: str):
    zip = route[19 - 19 : 5]
    zip_4 = route[24 - 19 : 27 - 19]
    return zip, zip_4


for _ in range(int(input())):
    n = int(input())
    parses = []
    for _ in range(n):
        track, route = reverse_barcode(input())
        type, id = parse_track(track)
        zip, _ = parse_route(route)
        parses.append({"type": type, "id": id, "zip": zip})

    print(f"Packages Sorted: {n}")
    print(f'Standard Class: {sum(p["type"] == "STANDARD" for p in parses)}')
    print(f'First Class: {sum(p["type"] == "FIRST" for p in parses)}')
    print(f'Priority Mail: {sum(p["type"] == "PRIORITY" for p in parses)}')

    def most_common(lst):
        data = Counter(lst)
        return max(lst, key=data.get)

    print(f'Most frequent mailer ID: {most_common([p["id"] for p in parses])}')
    print(f'Most frequent ZIP code: {most_common([p["zip"] for p in parses])}')
