"""
https://open.kattis.com/problems/cowcrane
Author: https://github.com/smh997/
"""
m, l = map(int, input().split())
M, L = map(int, input().split())
tm, tl = map(int, input().split())
val11 = abs(m) + abs(M-m)
val12 = val11 + abs(l-M) + abs(L-l)
val21 = abs(l) + abs(L-l)
val22 = val21 + abs(m-L) + abs(M-m)
val31 = abs(m) + abs(l-m) + abs(L-l)
val32 = val31 + abs(l-L) + abs(M-l)
val41 = abs(l) + abs(m-l) + abs(M-m)
val42 = val41 + abs(m-M) + abs(L-m)
if (val11 <= tm and val12 <= tl) or (val21 <= tl and val22 <= tm) or (val31 <= tl and val32 <= tm) or (val41 <= tm and val42 <= tl):
    print('possible')
else:
    print('impossible')