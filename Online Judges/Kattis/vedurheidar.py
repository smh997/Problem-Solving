"""
https://open.kattis.com/problems/vedurheidar
Author: https://github.com/smh997/
"""

v = int(input())
n = int(input())
for _ in range(n):
    a, b = map(str, input().split())
    print(a, 'lokud' if int(b) < v else 'opin')
