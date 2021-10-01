"""
https://open.kattis.com/problems/dicecup
Author: https://github.com/smh997/
"""
a, b = map(int, input().split())
for i in range(min(a,b)+1,max(a,b)+2):
    print(i)
