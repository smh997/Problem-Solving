"""
https://open.kattis.com/problems/skocimis
Author: https://github.com/smh997/
"""
a, b, c = map(int, input().split())
print(max(c-b-1,b-a-1))