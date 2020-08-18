#!/usr/bin/env python3
import sys
import random
from lib import *

seed(sys.argv[-1])

n = int(sys.argv[1])
m = int(sys.argv[2])

graph = random_connected_undirected_graph_uniform(n, m)
output_graph(n, with_random_weights(graph))

