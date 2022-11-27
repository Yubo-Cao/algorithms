import sys
from dataclasses import dataclass
import random

Point = tuple[float, float]


@dataclass
class Circle:
    x: float
    y: float
    r: float

    def intersection_with(self, c: "Circle") -> tuple[Point, Point]:
        x1, y1, r1 = self.x, self.y, self.r
        x2, y2, r2 = c.x, c.y, c.r
        dx, dy = x2 - x1, y2 - y1
        d = (dx**2 + dy**2) ** 0.5
        if d > r1 + r2:
            return None, None
        if d < abs(r1 - r2):
            return None, None
        if d == 0 and r1 == r2:
            return None, None
        a = (r1**2 - r2**2 + d**2) / (2 * d)
        h = (r1**2 - a**2) ** 0.5
        x3 = x1 + a * dx / d
        y3 = y1 + a * dy / d
        x4 = x3 - h * dy / d
        y4 = y3 + h * dx / d
        x5 = x3 + h * dy / d
        y5 = y3 - h * dx / d
        return (x4, y4), (x5, y5)


def get_distance(x, y):
    """Return the eucidiean distance between the x, y and the target."""
    print(f"P {x} {y}")
    sys.stdout.flush()
    dst = float(input())
    dst -= (x**2 + y**2) ** 0.5 * 2
    return dst / 2


def get_random_point() -> Point:
    x = random.random() * 3e5 - 1e5 * 1.5
    y = random.random() * 3e5 - 1e5 * 1.5
    return (x, y)


def get_target():
    """Return the target."""

    # random number between -1e6 and 1e6
    x1, y1 = get_random_point()
    x2, y2 = get_random_point()
    c1 = Circle(x1, y1, get_distance(x1, y1))
    c2 = Circle(x2, y2, get_distance(x2, y2))

    try:
        p1, p2 = c1.intersection_with(c2)
        # eliminate 1 candidate
        if get_distance(*p1) > get_distance(*p2):
            return p2
        return p1
    except TypeError:
        # sometimes, the choice of c1 and c2 is not good
        return get_target()


def main():
    n = int(input())
    for i in range(n):
        tp = get_target()
        print(f"B {tp[0]} {tp[1]}")
        sys.stdout.flush()
        result = input().strip()
        if result != "CORRECT" and result != "SUCCESS":
            break


if __name__ == "__main__":
    main()
