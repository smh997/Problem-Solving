"""
https://open.kattis.com/problems/bijele
Author: https://github.com/smh997/
"""
li = [1, 1, 2, 2, 2, 8]
res = [li[i] - a for i, a in enumerate(list(map(int, input().split())))]
for b in res:
    print(b, end=' ')
print()
