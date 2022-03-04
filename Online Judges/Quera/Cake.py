"""
https://quera.org/problemset/13819/
Author: https://github.com/smh997/
"""

w = int(input())
n = int(input())
s = 0
for i in range(n):
	a, b = map(int, input().split())
	s += a * b
print(s // w)