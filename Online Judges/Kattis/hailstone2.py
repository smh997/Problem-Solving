"""
https://open.kattis.com/problems/hailstone2
Author: https://github.com/smh997/
"""

n = int(input())
ans = 1
while n != 1:
    n = 3 * n + 1 if n % 2 else n // 2
    ans += 1
print(ans)