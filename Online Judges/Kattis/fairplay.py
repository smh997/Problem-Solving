"""
https://open.kattis.com/problems/fairplay
Author: https://github.com/smh997/
"""

li = []
n = int(input())
sa, sb = 0, 0
for i in range(n):
    a, b = map(int, input().split())
    li.append((a, b))
    sa += a
    sb += b
if n % 2 or (sa % (n // 2)) or (sb % (n // 2)):
    print('impossible')
    exit(0)
li.sort()
pa, pb = sa // (n // 2), sb // (n // 2)
for i in range(n // 2):
    if li[i][0] + li[n-1-i][0] != pa or li[i][1] + li[n-1-i][1] != pb:
        print('impossible')
        exit(0)
print('possible')