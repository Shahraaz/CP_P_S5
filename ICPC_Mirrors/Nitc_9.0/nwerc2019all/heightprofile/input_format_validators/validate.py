#!/usr/bin/env python3
from sys import stdin
import re
import sys

integer = "(0|-?[1-9]\d*)"
floating = "(" + integer + "|-0)" + "(\.\d)"
onefloat = re.compile(floating + "\n")
twoint = re.compile(integer + " " + integer + "\n")
manyint = re.compile("(" + integer + " )*" + integer + "\n")

line = stdin.readline()
assert twoint.match(line)
n, k = list(map(int, line.split()))
assert 1 <= n <= 10 ** 5 and 1 <= k <= 50

line = stdin.readline()
assert manyint.match(line)
a = list(map(int, line.split()))
assert len(a) == n + 1
for x in a:
    assert 0 <= x <= 10 ** 9

for i in range(k):
    line = stdin.readline()
    assert onefloat.match(line)
    assert not line.startswith("-0.0")

    q = float(line)
    assert -100 <= q <= 100

assert len(stdin.readline()) == 0
sys.exit(42)
