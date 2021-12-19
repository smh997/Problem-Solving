"""
https://open.kattis.com/problems/kolone
Author: https://github.com/smh997/
"""
n, m = map(int, input().split())
a = input()[::-1]
b = input()
t = int(input())
if t >= n+m:
    print(b, end='')
    print(a)
    exit(0)
bb = [' ' for c in range(m+n-t)] + [c for c in b] + [' ' for c in range(n+t)]
aa = [' ' for c in range(m)]+[c for c in a] + [' ' for c in range(m+n)]
for i in range(2*(n+m)):
    if aa[i] == ' ' and bb[i] == ' ':
        continue
    if aa[i] == ' ':
        print(bb[i], end='')
    elif bb[i] == ' ':
        print(aa[i], end='')
    else:
        print(bb[i], end='')
        print(aa[i], end='')
