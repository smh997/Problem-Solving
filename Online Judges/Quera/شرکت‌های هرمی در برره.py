"""
https://quera.org/problemset/10169/
Author: https://github.com/smh997/
"""
h, s = map(str, input().split())
h = int(h)
n = 2 ** (h + 1) - 1
d = 0
jaigah = 0
for i in range(len(s)):
    tedad = 2 ** d - 1
    n -= (jaigah * 2 + (tedad - jaigah))
    if s[i] == 'L':
        n -= 1
        jaigah *= 2
    else:
        n -= 2
        jaigah = jaigah * 2 + 1
    d += 1
print(n)