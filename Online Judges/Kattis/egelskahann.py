"""
Author https://github.com/smh997/
https://open.kattis.com/problems/egelskahann
"""

n = int(input())
ans = 1
for i in range(2, n+1):
    ans = (ans + 2) % i
    if not ans:
        ans = i
print(ans)
