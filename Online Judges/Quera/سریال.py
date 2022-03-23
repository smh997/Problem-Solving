"""
https://quera.org/problemset/10936/
Author: https://github.com/smh997/
"""
n, k = map(int, input().split())
li = list(map(int, input().split()))
m = 0
c = 1
for i in range(1, len(li)):
    if li[i] == li[i - 1] + 1:
        c += 1
    else:
        m = max(m, c)
        c = 1
m = max(m, c)
print(min(n, m + k))
