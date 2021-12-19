"""
https://open.kattis.com/problems/flexible
Author: https://github.com/smh997/
"""
n, p = map(int, input().split())
li=[0]
li.extend(list(map(int, input().split())))
li.append(n)
p+=2
res = []
for i in range(p-1):
  for j in range(i+1, p):
    if (li[j]-li[i]) not in res:
      res.append(li[j]-li[i])
res.sort()
for a in res:
  print(a, end=' ')
print()