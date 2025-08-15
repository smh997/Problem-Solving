"""
Author https://github.com/smh997/
https://open.kattis.com/problems/milkmystery
"""

n, k = map(int, input().split())
li = list(map(int, input().split()))
ans = sum(li[:k])
for i in range(1, n - k + 1):
    ans = max(ans, sum(li[i:i + k]))
print(ans)
