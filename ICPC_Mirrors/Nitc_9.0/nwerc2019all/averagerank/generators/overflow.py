#!/usr/bin/python3

import random

n = 300000
W = 300000
P = 1000000

points = [[] for _ in range(W)]

# Give everybody but one a point on the first day
points[0] = random.sample(range(1, n+1), n-1)

# Distribute the remaining points randomly.
for w in random.choices(range(1, W), k=P - len(points[0])):
    while True:
        c = random.choice(points[0])
        if c not in points[w]:
            points[w].append(c)
            break

print(n, W)
for ps in points: print(len(ps), *ps)
