"""
https://open.kattis.com/problems/beatspread
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    s, d = map(int, input().split())
    if s < d or (s-d) % 2:
        print('impossible')
        continue
    b = (s - d) // 2
    print(s - b, b)
