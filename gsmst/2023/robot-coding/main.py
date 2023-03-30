cmd = input() * 4
position = (0, 0)
velocity = (0, 1)

for c in cmd:
    if c == "G":
        position = (position[0] + velocity[0], position[1] + velocity[1])
    if c == "L":
        velocity = (-velocity[1], velocity[0])
    if c == "R":
        velocity = (velocity[1], -velocity[0])

print("TRUE" if position == (0, 0) else "FALSE")
