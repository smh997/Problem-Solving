"""
https://open.kattis.com/problems/moscowdream
Author: https://github.com/smh997/
"""
a, b, c, n = map(int, input().split())
print('NO' if not a or not b or not c or a + b + c < n or n < 3 else 'YES')