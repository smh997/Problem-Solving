"""
https://open.kattis.com/problems/countingclauses
Author: https://github.com/smh997/
"""
m, n = map(int, input().split())
for i in range(m):
    a, b, c = map(int, input().split())
print('unsatisfactory' if m < 8 else 'satisfactory')