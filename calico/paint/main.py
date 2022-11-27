import sys
sys.setrecursionlimit(10**6)

def solve(w, o, b, cow, cbo, cbw):
    """
    w: number of white paints
    o: number of orange paints
    b: number of blue paints

    cow: cost to convert white to orange
    cbo: cost to convert orange to blue
    cbw: cost to convert blue to white

    return: minimum cost to convert all paints to the same color
    """
    if w == o == b:
        return 0

    # find the cheapest way to convert 
    cow = min(cow, cbo + cbw)
    cbw = min(cbw, cow + cbo)
    cbo = min(cbo, cow + cbw)

    # cost to convert all to white
    cw = cow * o + cbw * b
    # cost to convert all to orange
    co = cow * w + cbo * b
    # cost to convert all to blue
    cb = cbw * w + cbo * o
    return min(cw, co, cb)


def main():
    for _ in range(int(input())):
        w, o, b, cow, cbo, cbw = map(int, input().split())
        print(solve(w, o, b, cow, cbo, cbw))

if __name__ == '__main__':
    main()