#!/usr/bin/env python3
import random
from typing import NamedTuple

random.seed(112233)

nmax = 500
xmax = 10**9

class TestCase(NamedTuple):
    distance: int
    jump_length: int
    jump_time: int
    intervals: list

def is_valid(tc):
    return all(0 < a and a < b and b < tc.distance and b-a <= tc.jump_length for (a,b) in tc.intervals) \
       and all(a < b for ((_,a),(b,_)) in zip(tc.intervals, tc.intervals[1:]))

def from_lengths(water, land):
    distance = 0
    intervals = []
    for k in range(len(land)):
        distance += water[k]
        intervals.append((distance, distance+land[k]))
        distance += land[k]
    distance += water[-1]
    return (distance, intervals)

def write_case(name, tc):
    with open('../data/secret/' + name + '.in', 'w') as f:
        f.write('{} {} {}\n'.format(tc.distance, tc.jump_length, tc.jump_time))
        f.write('{}\n'.format(len(tc.intervals)))
        for (a,b) in tc.intervals:
            f.write('{} {}\n'.format(a,b))

def rand(a,b):
    return random.randrange(a,b+1)



# Cases with varying lengths of jumps and water/land sections:

def short_intervals_long_jump(n):
    jump_length = rand(1,10**6)
    jump_time = rand(1,10**5)
    water = [rand(1,1000) for _ in range(n+1)]
    land = [rand(max(0,jump_length-1000),jump_length) for _ in range(n)]
    distance, intervals = from_lengths(water, land)
    return TestCase(distance, jump_length, jump_time, intervals)

for k in range(20,30):
    n = nmax if k >= 25 else rand(0,nmax)
    write_case(str(k)+'-short-intervals-long-jump', short_intervals_long_jump(n))

def long_intervals_short_jump(n):
    jump_length = rand(1,10**6)
    jump_time = rand(1,10**5)
    water = [rand(1,10**6) for _ in range(n+1)]
    land = [rand(1,jump_length+1) for _ in range(n)]
    distance, intervals = from_lengths(water, land)
    return TestCase(distance, jump_length, jump_time, intervals)

for k in range(30,40):
    n = nmax if k >= 35 else rand(0,nmax)
    write_case(str(k)+'-long-intervals-short-jump', long_intervals_short_jump(n))



# Completely random cases:

def random_case(n):
    distance = rand(2*n+1,xmax)
    coords = sorted(random.sample(range(1,distance),2*n))
    intervals = [(coords[2*i],coords[2*i+1]) for i in range(n)]
    jump_length = rand(max([b-a for (a,b) in intervals]+[1]),xmax)
    jump_time = rand(1,xmax)
    return TestCase(distance, jump_length, jump_time, intervals)

for k in range(70,80):
    write_case(str(k)+'-random', random_case(rand(0,nmax)))


# Some corner cases:
write_case('40-shortest', TestCase(1, 12345678, 55555, []))
write_case('41-long-jump', TestCase(xmax, xmax, xmax, [(1,2),(xmax-2,xmax-1)]))

# Create all cases with 0 <= n <= nmax, 0 <= s <= xmax, 1 <= d <= dmax, 1 <= t <= tmax:

def create_all_small_cases(nmax=3, xmax=12, dmax=5, tmax=5):
    k = 0
    for s in range(1,xmax+1):
        for n in range(nmax+1):
            def rec(xs,x):
                nonlocal k
                if len(xs) == 2*n:
                    intervals = [(xs[2*i],xs[2*i+1]) for i in range(n)]
                    for d in range(1,dmax+1):
                        for t in range(1,tmax+1):
                            name = 'small/{:05d}'.format(k)
                            tc = TestCase(s,d,t,intervals)
                            if is_valid(tc):
                                write_case(name, tc)
                                k += 1
                elif x < s:
                    rec(xs+[x],x+1)
                    rec(xs,x+1)
            rec([],1)
    print(k)

# create_all_small_cases()
