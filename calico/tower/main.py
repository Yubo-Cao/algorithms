"""
You’re given N towers numbered 1, 2, …, N arranged in a circle. The towers have
powers given by the sequence P1 , P2, …, PN, where Pi denotes the power of tower
i. Adjacent towers are connected by paths of length D1 , D2, …, DN, where the
distance between tower i and tower i + 1 is denoted by Di, and the distance
between tower N and tower 1 is denoted by DN. Find the minimum amount of time
needed to destroy all the towers. Herry starts with a power of zero, which
increases by one at the end of every hour. Upon arriving at a tower, he can
destroy it instantly if he has a power equal to or greater than the power of the
tower. Otherwise, he must wait inside the tower until his power matches that of
the tower—after which he can destroy the tower instantly. He can choose to start
at any tower he wishes, and can walk at a pace of one unit of distance per hour.
Once he begins, he can only travel around the circle in a clockwise
direction—despite all of his magic, Herry was never taught as a child how to
turn around.
"""

import sys
