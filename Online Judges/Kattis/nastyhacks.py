"""
https://open.kattis.com/problems/nastyhacks
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    r, ar, c = map(int, input().split())
    if ar-c < r:
        print("do not advertise")
    elif ar-c == r:
        print("does not matter")
    else:
        print("advertise")
