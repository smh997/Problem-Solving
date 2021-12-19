"""
https://open.kattis.com/problems/everywhere
Author: https://github.com/smh997/
"""
t = int(input())
s = set()
for i in range(t):
    s.clear()
    n = int(input())
    for j in range(n):
        s.add(input())
    print(len(s))
