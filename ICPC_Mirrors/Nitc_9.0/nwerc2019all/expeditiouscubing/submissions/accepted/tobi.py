import sys

def convert(n):
  l = n.split('.')
  return int(l[0])*1000 + int(l[1])*10

def parse(line):
  return [convert(n) for n in line.split()]

def best(times):
  times.sort()
  return times[1] + times[2] + times[3]

mine = parse(sys.stdin.readline())
theirs = 3 * parse(sys.stdin.readline())[0]

if best(mine[:] + [convert('20.00')+1]) <= theirs:
  print('infinite')
elif best(mine[:] + [0]) > theirs:
  print('impossible')
else:
  for i in reversed(range(20001)):
    if best(mine[:] + [i]) <= theirs:
      print('%s.%02d' % ((int)(i/1000), int((i%1000)/10)))
      break
