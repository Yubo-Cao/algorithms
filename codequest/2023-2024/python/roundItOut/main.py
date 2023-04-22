"""
The first line of your program's input, received from the standard input channel, will contain a
positive integer representing the number of test cases. Each test case will include a single line with
the following information, separated by spaces:
A decimal number,X
: A one- or two-character code indicating the rounding method to be used:
0HU =Half Up
0HD= Half Down
0U=Up
0D = Down
0HE = Half Even
0HO= Half Odd
An integer, P, indicating the number of decimal places to which X should be rounded
"""

"""
6
1.23 HU 1
1.23 HO 1
1.23 HD 1
5.0 U -1
5.0 HE -1
-4.205 D 2
"""


"""
1.2
1.2
1.2
10
0
-4.2
"""

from decimal import (
    Decimal,
    ROUND_HALF_UP,
    ROUND_HALF_DOWN,
    ROUND_UP,
    ROUND_DOWN,
    ROUND_HALF_EVEN,
    ROUND_CEILING,
)

num_cases = int(input())

for i in range(num_cases):
    x, method, p = input().split()
    x = Decimal(x)
    p = int(p)
    if method == "HU":
        result = x.quantize(Decimal("1." + "0" * p), rounding=ROUND_HALF_UP)
    elif method == "HD":
        result = x.quantize(Decimal("1." + "0" * p), rounding=ROUND_HALF_DOWN)
    elif method == "U":
        result = x.quantize(Decimal("1." + "0" * p), rounding=ROUND_UP)
    elif method == "D":
        result = x.quantize(Decimal("1." + "0" * p), rounding=ROUND_DOWN)
    elif method == "HE":
        result = x.quantize(Decimal("1." + "0" * p), rounding=ROUND_HALF_EVEN)
    elif method == "HO":
        if p >= 0:
            if x >= 0:
                result = Decimal(int(x * (Decimal(10)**p) + Decimal("0.5"))) / (Decimal(10)**p)
            else:
                result = Decimal(int(x * (Decimal(10)**p) - Decimal("0.5"))) / (Decimal(10)**p)
        else:
            result = x

    print(result)
