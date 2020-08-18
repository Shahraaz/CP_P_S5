T = sorted(map(float, raw_input().split()))
t = float(raw_input())

if sum(T[1:]) < 3*t + 1e-6: print 'infinite'
elif sum(T[:3]) > 3*t + 1e-6: print 'impossible'
else: print '%.2f' % (3*t-T[1]-T[2])
