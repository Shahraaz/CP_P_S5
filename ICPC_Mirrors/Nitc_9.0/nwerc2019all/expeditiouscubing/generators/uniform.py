#!/usr/bin/env python3
import sys
import random
from lib import *

seed(sys.argv[-1])

output(
    [ uniform() for _ in range(4) ],
    uniform(),
)

