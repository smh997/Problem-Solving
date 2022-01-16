"""
https://open.kattis.com/problems/simonsays
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    s = input()
    if s.startswith("Simon says"):
        print(s[11:])
