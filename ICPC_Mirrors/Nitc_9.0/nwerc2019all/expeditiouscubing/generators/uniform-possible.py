#!/usr/bin/env python3
import sys
import random
from lib import *

seed(sys.argv[-1])

have = [ uniform() for _ in range(4) ]
min_value = sum(sorted(have)[:3])/3.0
max_value = sum(sorted(have)[-3:])/3.0

output(
    have,
    uniform(min_value, max_value),
)

