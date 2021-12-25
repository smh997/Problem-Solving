"""
https://open.kattis.com/problems/recount
Author: https://github.com/smh997/
"""
d, m, flag, res = {}, 0, False, ''
while True:
    name = input()
    if name == '***':
        break
    if name not in d:
        d[name] = 0
    d[name] += 1
    if d[name] == m:
        flag = False
    elif d[name] > m:
        m = d[name]
        res = name
        flag = True
print(res if flag else 'Runoff!')
