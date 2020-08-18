import sys

scores = list(map(float, sys.stdin.readline().split()))
target = float(sys.stdin.readline())

always = True
ever = False
mx = 0
for i in range(0, 20*100+1):
    score = i / 100.0
    cur = sum(sorted([score] + scores)[1:-1]) / 3.0
    if cur <= target + 1e-9:
        mx = score
        ever = True
    else:
        always = False

if not ever:
    print('impossible')
elif always:
    print('infinite')
else:
    print('%0.2f' % mx)

