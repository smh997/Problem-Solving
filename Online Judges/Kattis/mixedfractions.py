"""
https://open.kattis.com/problems/mixedfractions
Author: https://github.com/smh997/
"""
while True:
    a, b = map(int, input().split())
    if a + b == 0:
        break
    print(a // b, a % b, '/', b)
