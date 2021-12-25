"""
https://open.kattis.com/problems/planetaris
Author: https://github.com/smh997/
"""
n, f = map(int, input().split())
e = [i+1 for i in list(map(int, input().split()))]
e.sort()
res = 0
for i in range(n):
    if f < e[i]:
        break
    res += 1
    f -= e[i]
print(res)