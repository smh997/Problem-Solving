"""
https://open.kattis.com/problems/dishonestlottery
Author: https://github.com/smh997/
"""

n = int(input())
cap = [0 for _ in range(51)]
ans = []
for i in range(10*n):
    li = list(map(int, input().split()))
    for a in li:
        cap[a] += 1
for a in range(1, 51):
    if cap[a] > 2 * n:
        ans.append(a)
print(-1 if not ans else ' '.join([str(a) for a in ans]))