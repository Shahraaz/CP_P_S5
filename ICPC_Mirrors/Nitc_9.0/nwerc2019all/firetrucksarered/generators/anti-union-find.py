#!/usr/bin/env python3

from pathlib import Path
import random
random.seed(1234)

# we need 2*(n-1) integers to construct the testcase.
n = 100001

def star(n):
    colours = [[] for _ in range(n)]
    for i in range(n-1):
        colours[i].append(i+1)
        colours[i+1].append(i+1)
    return colours

def line(n):
    colours = [[] for _ in range(n)]
    for i in range(n-1):
        colours[0].append(i+1)
        colours[i+1].append(i+1)
    return colours

def print_case(data, name):
    f = (Path('../data/secret')/name).with_suffix('.in').open('w')
    print(len(data), file=f)
    for cs in data: print(len(cs), *cs, file=f)

print_case(star(n), '80_star')
print_case(line(n), '81_line')
print_case(list(reversed(star(n))), '82_star_reverse')
print_case(random.sample(line(n), k=n), '83_line_shuffled')
