import sys
import random
from heapq import *

def seed(s):
    secret = 'dF0ow5p7mkfkbfTeMiNGSlmBrllFdVHM'
    random.seed(secret + s)

def random_tree_uniform(n):
    if n == 1:
        return []

    seq = [ random.randint(0,n-1) for _ in range(n-2) ]
    deg = [1]*n
    for v in seq:
        deg[v] += 1

    ones = []
    for i, d in enumerate(deg):
        if d == 1:
            ones.append(i)

    heapify(ones)
    es = []
    for u in seq:
        v = heappop(ones)
        es.append((u,v))
        deg[u] -= 1
        deg[v] -= 1
        if deg[u] == 1:
            heappush(ones, u)

    u = 0
    while deg[u] != 1: u += 1
    v = u+1
    while deg[v] != 1: v += 1

    es.append((u,v))
    return es

def random_connected_undirected_graph_uniform(n, max_edges):
    graph = set(random_tree_uniform(n))
    m = n*(n-1)//2

    if m <= 10**5:
        es = [ (u,v) for u in range(n) for v in range(u+1,n) ]
        random.shuffle(es)
        for (u,v) in es:
            if len(graph)+1 > max_edges:
                break
            if (u,v) in graph or (v,u) in graph:
                continue
            graph.add((u,v))
    else:
        while len(graph)+1 <= max_edges:
            u = random.randint(0, n-1)
            v = random.randint(0, n-1)
            if u == v:
                continue
            if (u,v) in graph or (v,u) in graph:
                continue
            graph.add((u,v))

    return list(graph)

def shuffle_edges(edges):
    edges = list(edges)
    random.shuffle(edges)
    for i in range(len(edges)):
        if random.randint(0,1) == 1:
            if len(edges[i]) == 2:
                edges[i] = (edges[i][1], edges[i][0])
            elif len(edges[i]) == 3:
                edges[i] = (edges[i][1], edges[i][0], edges[i][2])
            else:
                assert False
    return edges

def shuffle_vertices(n, edges):
    vertex_permutation = list(range(1,n-1))
    random.shuffle(vertex_permutation)
    vertex_permutation = [0] + vertex_permutation + [n-1]

    edges = list(edges)
    for i in range(len(edges)):
        if len(edges[i]) == 2:
            edges[i] = (vertex_permutation[edges[i][0]], vertex_permutation[edges[i][1]])
        elif len(edges[i]) == 3:
            edges[i] = (vertex_permutation[edges[i][0]], vertex_permutation[edges[i][1]], edges[i][2])
        else:
            assert False

    return edges

def with_random_weights(edges, min_weight=1, max_weight=10**9):
    return [ (u,v,random.randint(min_weight, max_weight)) for (u,v) in edges ]

def output_graph(n, edges):
    edges = shuffle_edges(edges)
    edges = shuffle_vertices(n, edges)

    sys.stdout.write('%d %d\n' % (n, len(edges)))
    for edge in edges:
        if len(edge) == 2:
            sys.stdout.write('%d %d\n' % (edge[0]+1, edge[1]+1))
        elif len(edge) == 3:
            sys.stdout.write('%d %d %d\n' % (edge[0]+1, edge[1]+1, edge[2]))
        else:
            assert False

