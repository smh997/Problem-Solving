"""
https://open.kattis.com/problems/froggie
Author: https://github.com/smh997/
"""
def inrange(i, j, L, W):
    return 0 <= i < L and 0 <= j < W


L, W = map(int, input().split())
li = []
for i in range(L):
    O, I, S = map(int, input().split())
    li.append((O, I, S, True if i % 2 else False))

P, M = map(str, input().split())
P = int(P)
level = L
safe = True
time = 0
for i in range(len(M)):
    if M[i] == 'U':
        level -= 1
    elif M[i] == 'D':
        level += 1
    elif M[i] == 'R':
        P += 1
    elif M[i] == 'L':
        P -= 1
    if level < 0:
        break
    if inrange(level, P, L, W):
        ans = True
        p = P
        st, interv, speed, dir = li[level][0], li[level][1], li[level][2], li[level][3]
        if dir:
            p = W - 1 - p
        aa = st + time * speed
        while aa < W:
            aa += interv
        while aa >= p:
            aa -= interv
        if not speed:
            ans = True if p == aa + interv else False
        else:
            ans = True if aa + min(1, speed) <= p <= aa + speed else False
        if ans:
            safe = False
    time += 1
if level >= 0:
    safe = False
print('safe' if safe else 'squish')
