#!/usr/bin/env python3
from sys import stdin
import re
import sys

integer = "(0|-?[1-9]\d*)"
twoint = re.compile(integer + " " + integer + "\n")
manyint = re.compile("(" + integer + " )*" + integer + "\n")

line = stdin.readline()
assert twoint.match(line)
n, d = list(map(int, line.split()))
assert 1 <= n <= 3 * 10 ** 5 and 1 <= d <= 3 * 10 ** 5

tot_points = 0
for i in range(d):
    line = stdin.readline()
    assert manyint.match(line)
    a = list(map(int, line.split()))
    assert len(a) >= 1 and len(a) == a[0] + 1
    tot_points += a[0]
    for x in a[1:]:
        assert 1 <= x <= n

    ids = set(a[1:])
    assert len(ids) == a[0]

assert tot_points <= 10**6

assert len(stdin.readline()) == 0
sys.exit(42)
