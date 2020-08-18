import sys
import random
from heapq import *

def seed(s):
    secret = 'dF0ow5p7mkfkbfTeMiNGSlmBrllFdVHM'
    random.seed(secret + s)

def uniform(a=1, b=20):
    return random.random() * (b-a) + a

def output(scores, target):
    assert len(scores) == 4
    sys.stdout.write('%s\n' % ' '.join([ '%0.2f' % s for s in scores ]))
    sys.stdout.write('%0.2f\n' % target)

