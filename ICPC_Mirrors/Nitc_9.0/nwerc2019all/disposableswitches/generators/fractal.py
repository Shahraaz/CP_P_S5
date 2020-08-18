#!/usr/bin/env pypy
import sys
import random
from lib import *

weight_type = sys.argv[1]

seed(sys.argv[-1])

RAND = (1,10**9)
LO = (1,100)
HI = (1000,10**9)

while True:

    graphs = [
        [(0,1, 1.0)],
        [(0,1, 0.5),(1,2, 0.5)],
        [(0,1, 0.5),(1,2, 0.5),(0,2, 1.0)],
        [(0,1,0.5),(1,3,0.5),(0,2,0.5),(2,3,0.5)],
        [(0,1,0.5),(1,2,0.25),(2,3,0.25),(0,3,1.0),(1,3,0.5)],
    ]

    random.shuffle(graphs)
    graphs = graphs[:random.randint(1,len(graphs))]

    piece_cnt = random.randint(2,5)
    pieces = []
    for i in range(piece_cnt):
        piece = [ (a,b,
                random.randint(0,piece_cnt-1),
                frac
                ) for (a,b,frac) in random.choice(graphs) ]
        pieces.append(piece)

    seen = set()
    child = {}
    def has_cycle(cur):
        if cur in seen:
            return False
        seen.add(cur)

        for (a,b,t,f) in pieces[cur]:
            if t in child:
                found = False
                tmp = t
                while True:
                    found = found or len(pieces[tmp]) > 2
                    if tmp not in child:
                        break
                    tmp = child[tmp]
                if found:
                    return True
                continue

            child[cur] = t
            if has_cycle(t):
                return True
            del child[cur]

        return False

    cyc = has_cycle(0)
    if cyc:
        break

n = 2
graph = [ (0, 1, 0, 10**9) ]

def vertices(es):
    return max([ v for e in es for v in e[:2] ]) + 1

at = 2
while True:

    es = []
    for (a,b,t,w) in graph:
        cur_vertices = vertices(pieces[t])
        for (p,q,t2,frac) in pieces[t]:
            curw = max(1, round(w * frac))

            if p == 0:
                p = a
            elif p == cur_vertices-1:
                p = b
            else:
                p = at + p-1
            if q == 0:
                q = a
            elif q == cur_vertices-1:
                q = b
            else:
                q = at + q-1

            es.append((p,q,t2,curw))
        at += cur_vertices-2

    if at > 2000 or len(es) > 10**4:
    # if at > 200 or len(es) > 10**3:
        break
    graph = es

n = vertices(graph)
for i in range(len(graph)):
    a,b,_,w = graph[i]
    if a == 1:
        a = n-1
    elif a == n-1:
        a = 1
    if b == 1:
        b = n-1
    elif b == n-1:
        b = 1

    if weight_type == 'random':
        w = random.randint(1, 10**9)
    elif weight_type == 'exact':
        pass
    elif weight_type == 'bias':
        w += random.randint(-1,1)
    else:
        assert False

    w = max(w, 1)
    w = min(w, 10**9)
    graph[i] = (a,b,w)

output_graph(n, graph)

