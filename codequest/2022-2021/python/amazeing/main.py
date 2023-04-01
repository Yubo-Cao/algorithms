from collections import deque
from typing import Literal

CellType = Literal["entry", "exit", "default"]
Cell = tuple[int, int, CellType]


def parse_cell(
    x: int,
    y: int,
    maze: list[str],
    parse_children=False,
) -> tuple[Cell, tuple[Cell, ...]]:
    t: CellType = "default"
    if y == 0:
        if maze[y][x + 1 : x + 3] == "vv":
            t = "entry"
        elif maze[y][x + 1 : x + 3] == "^^":
            t = "exit"
    elif y == len(maze) - 2:
        if maze[y][x + 1 : x + 3] == "^^":
            t = "entry"
        elif maze[y][x + 1 : x + 3] == "vv":
            t = "exit"
    if x == 0:
        if maze[y + 1][x] == ">":
            t = "entry"
        elif maze[y + 1][x] == "<":
            t = "exit"
    elif x == len(maze[0]) - 4:
        if maze[y + 1][x + 3] == "<":
            t = "entry"
        elif maze[y + 1][x + 3] == ">":
            t = "exit"

    if not parse_children:
        return (x, y, t), tuple()

    children: list[Cell] = []
    if maze[y][x + 1 : x + 3] == "  " and y > 0:
        children.append(parse_cell(x, y - 2, maze)[0])
    if maze[y + 2][x + 1 : x + 3] == "  " and y < len(maze) - 2:
        children.append(parse_cell(x, y + 2, maze)[0])
    if maze[y + 1][x] == " " and x > 0:
        children.append(parse_cell(x - 3, y, maze)[0])
    if maze[y + 1][x + 3] == " " and x < len(maze[0]) - 3:
        children.append(parse_cell(x + 3, y, maze)[0])

    return (x, y, t), tuple(children)


def solve() -> None:
    h, w = map(int, input().split())
    maze = [input() for _ in range(h)]

    entry: tuple[int, int, CellType] | None = None
    exit: tuple[int, int, CellType] | None = None

    graph: dict[tuple[int, int], tuple[Cell, ...]] = {}

    for y in range(0, h - 1, 2):
        for x in range(0, w - 1, 3):
            (x, y, type), children = parse_cell(x, y, maze, parse_children=True)
            if type == "entry":
                entry = (x, y, type)
            if type == "exit":
                exit = (x, y, type)
            graph[(x, y)] = children
    assert entry is not None, "No entry found"
    assert exit is not None, "No exit found"

    queue = deque([(entry, 0)])
    visited = set()

    while queue:
        (x, y, type), length = queue.popleft()
        if (x, y) in visited:
            continue
        visited.add((x, y))
        if type == "exit":
            break
        for child in graph[(x, y)]:
            queue.append((child, length + 1))

    print(length + 1)


for _ in range(int(input())):
    solve()
