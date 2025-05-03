"""
https://open.kattis.com/problems/simone
Author: https://github.com/smh997/
"""

n, k = map(int, input().split())
li = list(map(int, input().split()))
cap = [li.count(i+1) for i in range(k)]
mi = min(cap)
res = [str(i+1) for i in range(k) if cap[i] == mi]
print(len(res))
print(' '.join(res))