"""
https://open.kattis.com/problems/titlecost
Author: https://github.com/smh997/
"""

s, c = map(str, input().split())
print(len(s) if len(s) < float(c) else c)