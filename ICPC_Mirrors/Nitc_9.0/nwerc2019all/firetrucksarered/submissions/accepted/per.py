from collections import defaultdict
n = int(raw_input())

by_num = defaultdict(lambda: [])
nums = [[] for _ in range(n)]

for i in range(n):
    for d in map(int, raw_input().split()[1:]):
        nums[i].append(d)
        by_num[d].append(i)

seen = [False]*n
out = []
seen[0] = True
Q = [0]
while Q:
    i = Q.pop()
    for d in nums[i]:
        for j in by_num[d]:
            if not seen[j]:
                out.append((i, j, d))
                Q.append(j)
                seen[j] = True
        by_num[d] = []

if len(out) < n-1:
    print 'impossible'
else:
    print '\n'.join('%d %d %d' % (i+1, j+1, d) for (i, j, d) in out)
