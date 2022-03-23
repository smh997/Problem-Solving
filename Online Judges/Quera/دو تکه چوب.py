"""
https://quera.org/problemset/138021/
Author: https://github.com/smh997/
"""
a, b = map(int, input().split())
c, d = max(a, b), min(a, b)
bb = c / 2
aa = bb
cc = d
li = [aa, bb, cc]
li.sort()
if li[2] < li[1] + li[0]:
    print('YES')
else:
    print('NO')
