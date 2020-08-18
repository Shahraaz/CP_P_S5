#!/usr/bin/env python3
import sys
import random
from lib import *

from_list = sys.argv[1].lower() == 'from_list'
seed(sys.argv[-1])

arr = []
while len(arr) < 4:
    cur = uniform()
    cnt = random.randint(1, 4-len(arr))
    for t in range(cnt):
        arr.append(cur)

random.shuffle(arr)
output(
    arr,
    random.choice(arr) if from_list else uniform()
)

