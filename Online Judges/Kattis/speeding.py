"""
https://open.kattis.com/problems/speeding
Author: https://github.com/smh997/
"""

n = int(input())
t, d = map(int, input().split())
mx = 0
for _ in range(1, n):
    t2, d2 = map(int, input().split())
    mx = max((d2-d)//(t2-t), mx)
    t, d = t2, d2
print(mx)