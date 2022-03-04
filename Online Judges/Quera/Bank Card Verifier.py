"""
https://quera.org/problemset/13819/
Author: https://github.com/smh997/
"""
r = []
while True:
    a = list(input().split())
    if a[0][0] =='0':
        break
    r.clear()
    for e in a:
        r.append(int(e[0]) * 2 - (9 if int(e[0]) * 2 > 9 else 0))
        r.append(int(e[1]))
        r.append(int(e[2]) * 2 - (9 if int(e[2]) * 2 > 9 else 0))
        r.append(int(e[3]))
    if sum(r) % 10 == 0:
        print("Yes")
    else:
        print("No")