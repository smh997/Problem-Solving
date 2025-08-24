"""
Author https://github.com/smh997/
https://open.kattis.com/problems/nafnatalning
"""

n, p = map(int, input().split())
a = list(map(int, input().split()))
li = [0] * 1001
ans = 0
for i in a:
    li[i] += 1
for i in range(1, 1001):
    ans += (li[i] * (li[i] - 1) // 2) * i * i
    for j in range(i+1, 1001):
        ans += li[i] * li[j] * i * j
print(ans // p + (ans % p > 0))
