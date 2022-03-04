"""
https://quera.org/problemset/33026/
Author: https://github.com/smh997/
"""
import json
n = int(input())
d = dict()
for i in range(n):
    s = input()
    if ':=' in s:
        aa, v = map(str, s.split(':='))
        aa = aa.strip()
        v = v.strip()
        d[aa] = json.loads(v)
    else:
        a = s[6:]
        name = a[:a.index('[')]
        value = json.loads(a[a.index('[') + 1: a.index(']')])
        print(d[name][value])

