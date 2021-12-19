"""
https://open.kattis.com/problems/lineup
Author: https://github.com/smh997/
"""
n = int(input())
li = []
for i in range(n):
    li.append(input())
main = li.copy()
li.sort()
d = list(reversed(li))
for i in range(len(main)):
    if main[i] != li[i]:
        break
else:
    print('INCREASING')
    exit(0)
for i in range(len(main)):
    if main[i] != d[i]:
        break
else:
    print('DECREASING')
    exit(0)
print('NEITHER')
