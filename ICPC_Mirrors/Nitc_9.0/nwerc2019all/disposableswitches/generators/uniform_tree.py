#!/usr/bin/env python3
import sys
import random
from lib import *

seed(sys.argv[-1])

n = int(sys.argv[1])

graph = random_tree_uniform(n)
output_graph(n, with_random_weights(graph))

