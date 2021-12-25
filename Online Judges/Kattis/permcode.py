"""
https://open.kattis.com/problems/permcode
Author: https://github.com/smh997/
"""
def calc_pos(ss):
    di = {}
    for ii in range(len(ss)):
        di[ss[ii]] = ii
    return di


while True:
    x = int(input())
    if x == 0:
        break
    s = input()
    p = input()
    c = input()
    n = len(c)
    mp = calc_pos(s)
    d = (int(n ** 1.5) + x) % n
    m = ['' for _ in range(n)]
    m[d] = p[mp[c[d]]]
    j, i = d, (d-1+n) % n
    while i != d:
        m[i] = p[mp[c[i]] ^ mp[m[j]]]
        i, j = (i - 1 + n) % n, (j - 1 + n) % n
    print(''.join(m))
