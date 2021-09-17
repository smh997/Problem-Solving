"""
https://open.kattis.com/problems/cardtrick2
Author: https://github.com/smh997/
"""
t = int(input())
for i in range(t):
    n = int(input())
    res = [str(n)]
    for j in reversed(range(1, n)):
        res.insert(0, str(j))
        for k in range(j):
            a = res.pop()
            res.insert(0, a)
    print(' '.join(res))