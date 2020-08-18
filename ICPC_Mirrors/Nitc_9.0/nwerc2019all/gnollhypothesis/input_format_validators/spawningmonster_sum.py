# assumes that basic validations happen in checktestdata
import sys

raw_input()
sum = 0
ss = raw_input().split()
for s in ss:
    if '.' in s:
        (bp,ap) = s.split('.')
        while len(ap) < 6:
            ap = ap + '0'
        sum = sum + int(ap) + int(bp)*10**6
    else:
        sum = sum + int(s)*10**6
if sum == 100*10**6:
    sys.exit(42)
else:
    sys.stderr.write('sum was %s\n' % sum)
    sys.exit(43)
