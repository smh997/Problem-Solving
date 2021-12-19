"""
https://open.kattis.com/problems/heirsdilemma
Author: https://github.com/smh997/
"""
L, R = map(int, input().split())
ans = 0
for i in range(L, R+1):
    if '0' in str(i):
        continue
    s = set()
    for j in str(i):
        s.add(int(j))
    if len(s) < 6:
        continue
    flag = True
    for j in str(i):
        if i % int(j):
            flag = False
            break
    if flag:
        ans += 1
print(ans)