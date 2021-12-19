"""
https://open.kattis.com/problems/fiftyshades
Author: https://github.com/smh997/
"""
n = int(input())
res = 0
p = False
for i in range(n):
    inp = input()
    if 'pink' in inp.lower():
        res += 1
        p = True
    elif 'rose' in inp.lower():
        res += 1
print('I must watch Star Wars with my daughter' if not p else res)