"""
https://open.kattis.com/problems/functionalfun
Author: https://github.com/smh997/
"""

import sys


def is_surjective(domain, codomain, mp):
    for c in codomain:
        if c not in mp.values():
            return False
    return True


def is_injective(domain: list, codomain: list, mp: dict):
    li = list(mp.values())
    for c in codomain:
        if li.count(c) > 1:
            return False
    return True


lines = sys.stdin.readlines()
it = 0
while it != len(lines):
    domain = lines[it].split()[1:]
    codomain = lines[it+1].split()[1:]
    mp = {}
    it += 2
    n = int(lines[it])
    it += 1
    notfun = False
    for i in range(n):
        a, b = map(str, lines[it].strip().split(' -> '))
        it += 1
        if notfun:
            continue
        if a in mp:
            notfun = True
            continue
        mp[a] = b
    if notfun:
        print('not a function')
    elif is_surjective(domain, codomain, mp):
        if is_injective(domain, codomain, mp):
            print('bijective')
        else:
            print('surjective')
    elif is_injective(domain, codomain, mp):
        print('injective')
    else:
        print('neither injective nor surjective')
