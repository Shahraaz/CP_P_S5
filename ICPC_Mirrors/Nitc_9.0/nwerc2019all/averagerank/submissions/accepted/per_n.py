(n, d) = map(int, raw_input().split())
debt = [0]*(d+1)
cur_rank = [1]*(d+1)
last_change = [0]*(d+1)
cur_score = [0]*n
ranksum = [0]*n

def cur_debt(s, day):
    return (day-last_change[s])*cur_rank[s] + debt[s]

for day in range(d):
    for i in map(int, raw_input().split()[1:]):
        i -= 1
        s = cur_score[i]
        ranksum[i] += cur_debt(s, day) - cur_debt(s+1, day)
        cur_score[i] += 1
        debt[s] += (day-last_change[s])*cur_rank[s]
        cur_rank[s] += 1
        last_change[s] = day

print '\n'.join('%.9f' % (1.0*(ranksum[i]+cur_debt(cur_score[i], d))/d) for i in range(n))
