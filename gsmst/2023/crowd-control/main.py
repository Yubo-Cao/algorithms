from typing import cast

Room = tuple[int, int]  # students, capacity
rd = lambda: cast(Room, tuple(tuple(map(int, input().split()))))
mllh, lllh, cafe = rd(), rd(), rd()


def move(fr: Room, to: Room) -> tuple[Room, Room]:
    mv = min(fr[0], to[1] - to[0])
    fr = (fr[0] - mv, fr[1])
    to = (to[0] + mv, to[1])
    return fr, to


# move from mllh -> lllh, lllh -> cafe, cafe -> mllh
def cyclic_move(mllh: Room, lllh: Room, cafe: Room) -> tuple[Room, Room, Room]:
    mllh, lllh = move(mllh, lllh)
    lllh, cafe = move(lllh, cafe)
    cafe, mllh = move(cafe, mllh)
    return mllh, lllh, cafe


for _ in range(20):
    mllh, lllh, cafe = cyclic_move(mllh, lllh, cafe)

print(mllh[0], lllh[0], cafe[0], sep="\n")