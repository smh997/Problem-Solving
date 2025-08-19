"""
Author https://github.com/smh997/
https://open.kattis.com/problems/happyhibernation
"""

n, h, t = map(int, input().split())
li = list(map(int, input().split()))
c = 0
f = True
for i in range(n):
    if li[i] > t:
        c = 0
        continue
    c += 1
    if h == c:
        print(i - h + 1)
        f = False
        break
if f:
    print('Too hot!')
