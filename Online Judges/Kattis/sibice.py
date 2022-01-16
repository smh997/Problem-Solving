"""
https://open.kattis.com/problems/sibice
Author: https://github.com/smh997/
"""
n, w, h = map(int, input().split())
maxl = int((w**2 + h**2)**0.5)
for i in range(n):
    a = int(input())
    if a <= maxl:
        print("DA")
    else:
        print("NE")
