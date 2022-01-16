"""
https://open.kattis.com/problems/transitwoes
Author: https://github.com/smh997/
"""
s, t, n = map(int, input().split())
w = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))
res = s
for i in range(n):
    if res > t:
        print('no')
        exit(0)
    res += w[i]
    res += (c[i] - res % c[i] if res % c[i] else 0) + b[i]
print('yes' if res + w[n] <= t else 'no')