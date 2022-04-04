"""
https://open.kattis.com/problems/knitpicking
Author: https://github.com/smh997/
"""
n = int(input())
left_socks, right_socks, any_socks = dict(), dict(), dict()
socks_set = set()
socks = {
    'any': any_socks, 
    'left': left_socks,
    'right': right_socks
}
for i in range(n):
    name, fit, c = map(str, input().split())
    c = int(c)
    socks_set.add(name)
    socks[fit][name] = c
res = 1
possible = False
for name in socks_set:
    ls = left_socks.get(name, 0)
    rs = right_socks.get(name, 0)
    anys = any_socks.get(name, 0)
    mx = max(ls, rs)
    if not mx and anys:
        mx = 1
    res += mx
    possible = (anys > 1 or anys * rs != 0 or anys * ls != 0 or ls * rs != 0 or possible)
print(res if possible else 'impossible')

