(n, m) = map(int, raw_input().split())
E = [map(int, raw_input().split()) for _ in range(m)]
E.extend([(v,u,w) for (u,v,w) in E])

cur_dist = [1<<50]*(n+1)
cur_dist[1] = 0
min_dist = [cur_dist]
cands = []
def below(C1, C2, C3):
    return (C3[0]-C2[0])*(C1[1]-C2[1]) < (C2[0]-C1[0])*(C2[1]-C3[1])
def add_cand(C):
    while len(cands) >= 2 and below(cands[-2], cands[-1], C):
        cands.pop()
    cands.append(C)
for hops in range(1, n):
    new_dist = [x for x in cur_dist]
    for (u, v, w) in E:
        new_dist[v] = min(new_dist[v], cur_dist[u] + w)
    if new_dist[-1] < 1<<50: add_cand((hops, new_dist[-1]))
    cur_dist = new_dist
    min_dist.append(cur_dist)

unsafe = [[0]*(n+1) for _ in range(n)]
for (hops, _) in cands:
    unsafe[hops][-1] = True
for hops in range(n-1, 0, -1):
    for (u, v, w) in E:
        if unsafe[hops][v] and min_dist[hops-1][u] + w == min_dist[hops][v]:
            unsafe[hops-1][u] = True
v_poss = [u for u in range(1,n+1) if not any(unsafe[hops][u] for hops in range(n))]
print len(v_poss)
print ' '.join(map(str, v_poss))
