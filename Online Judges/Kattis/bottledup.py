"""
https://open.kattis.com/problems/bottledup
Author: https://github.com/smh997/
"""
n, v1, v2 = map(int, input().split())
res1 = res2 = 0
it = 0
flag = True
while it * v2 <= n:
    if not (n - it * v2) % v1:
        print((n - it * v2) // v1, it)
        flag = False
        break
    it += 1

if flag:
    print('Impossible')
