#!/usr/bin/env python3

from pathlib import Path
import random

# Generate testdata of the following types:
# - increasing absolute values, random sign
# - decreasing absolute values, random sign
# - decreasing to the middle, than increasing
# - increasing to the middle, than decreasing

n = 500000

M = 10**9

def add_signs(l): return [random.choice([-1, 1]) * x for x in l]

def increasing(n): return sorted(random.sample(range(0, M), n))
def decreasing(n): return list(reversed(increasing(n)))

random.seed("seed")

def write(name, values):
    with Path(f'../data/secret/5e5/{name}.in').open('w') as f:
        print(len(values), random.randint(1, M), random.randint(1, M), file=f)
        print(*values, file=f)

# Only add to the end of this list to keep random number generation constant.
write('60-increasing', increasing(n))
write('61-decreasing', decreasing(n))
write('62-inc-dec', increasing(n//2) + decreasing((n+1)//2))
write('63-dec-inc', decreasing(n//2) + increasing((n+1)//2))
write('64-increasing-signs', add_signs(increasing(n)))
write('65-decreasing-signs', add_signs(decreasing(n)))
write('66-inc-dec-signs', add_signs(increasing(n//2) + decreasing((n+1)//2)))
write('66-dec-inc-signs', add_signs(decreasing(n//2) + increasing((n+1)//2)))
