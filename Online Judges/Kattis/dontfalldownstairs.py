"""
https://open.kattis.com/problems/dontfalldownstairs
Author: https://github.com/smh997/
"""

n = int(input())
li = list(map(int, input().split())) + [0]
ans = 0
for i in range(n):
    ans += max(0, li[i] - li[i+1] - 1)
print(ans)