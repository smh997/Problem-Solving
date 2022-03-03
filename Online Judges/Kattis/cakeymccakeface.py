"""
https://open.kattis.com/problems/cakeymccakeface
Author: https://github.com/smh997/
"""
n = int(input())
m = int(input())
en = list(map(int, input().split()))
ex = list(map(int, input().split()))
mp = dict()
for i in range(n):
    for j in range(m):
        if en[i] <= ex[j]:
            val = ex[j] - en[i]
            if val not in mp:
                mp[val] = 0
            mp[val] += 1
if not len(mp):
    print(0)
    exit(0)
mx = max(mp.values())
res = min([k for k, v in mp.items() if v == mx])
print(res)
