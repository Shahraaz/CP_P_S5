#!/usr/bin/env python3
import collections

n = int(input())
items = [set() for i in range(n)]
having = collections.defaultdict(list)
for i in range(n):
  items[i] = input().split()[1:]
  for j in items[i]:
    having[j] += [i]

solved = set([0])
answer = []
todo = [0]
while len(todo) > 0:
  x = todo.pop()
  for j in items[x]:
    for y in having[j]:
      if y not in solved:
        answer += [(x, y, j)]
        solved.add(y)
        todo += [y]

if len(solved) == n:
  for x,y,a in answer:
    print(x+1,y+1,a)
else:
  print('impossible')
