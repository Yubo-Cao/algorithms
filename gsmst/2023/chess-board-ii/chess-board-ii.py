board = [list(input().replace(" ", "")) for _ in range(8)]


def fd(char: str) -> list[tuple[int, int]]:
    result = []
    for i in range(8):
        for j in range(8):
            if board[i][j] == char:
                result.append((i, j))
    return result


king = fd("x")[0]
knights = fd("k")
rooks = fd("r")
bishops = fd("b")
queens = fd("q")


def check(king):
    knight_moves = [
        (-1, -2),
        (-1, 2),
        (1, -2),
        (1, 2),
        (-2, -1),
        (-2, 1),
        (2, -1),
        (2, 1),
    ]
    for knight in knights:
        for move in knight_moves:
            if (
                0 <= knight[0] + move[0] < 8
                and 0 <= knight[1] + move[1] < 8
                and board[knight[0] + move[0]][knight[1] + move[1]] == "x"
            ):
                return True
    for rook in rooks:
        if rook[0] == king[0] or rook[1] == king[1]:
            return True
    for bishop in bishops:
        if abs(bishop[0] - king[0]) == abs(bishop[1] - king[1]):
            return True
    for queen in queens:
        if (
            queen[0] == king[0]
            or queen[1] == king[1]
            or abs(queen[0] - king[0]) == abs(queen[1] - king[1])
        ):
            return True
    return False


print(
    "TRUE"
    if sum(
        check((min(max(king[0] + x, 0), 7), min(max(king[1] + y, 0), 7)))
        for x in [-1, 0, 1]
        for y in [-1, 0, 1]
    )
    > 3
    else "FALSE"
)
