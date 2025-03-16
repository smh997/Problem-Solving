"""
https://open.kattis.com/problems/bergur
Author: https://github.com/smh997/
"""

n = int(input())
li = list(map(int, input().split()))
ans = 0
m = li[-1]
for i in reversed(range(n)):
    m = min(li[i], m)
    ans += m
print(ans)
    