(n, d) = map(int, raw_input().split())
by_score = [set(range(n))] + [set() for _ in range(d)]
debt = [0]*(d+1)
cur_score = [0]*n
ranksum = [0]*n

for _ in range(d):
    for i in map(int, raw_input().split()[1:]):
        i -= 1
        s = cur_score[i]
        ranksum[i] += debt[s] - debt[s+1]
        by_score[s].remove(i)
        by_score[s+1].add(i)
        cur_score[i] += 1
    r = 1
    for i in range(_+1, -1, -1):
        debt[i] += r
        r += len(by_score[i])

print '\n'.join('%.9f' % (1.0*(ranksum[i]+debt[cur_score[i]])/d) for i in range(n))
