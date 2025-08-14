"""
Author https://github.com/smh997/
https://open.kattis.com/problems/kingskeep
"""
n = int(input())
li = list(list(map(int, input().split())) for _ in range(n))
ans = 1e9
for i in range(n):
    cost = 0
    for j in range(n):
        if i == j:
            continue
        cost += ((li[i][0] - li[j][0]) ** 2 + (li[i][1] - li[j][1]) ** 2) ** 0.5
    ans = min(ans, cost/(n - 1))
print(ans)
