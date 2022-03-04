"""
https://quera.org/problemset/26110/
Author: https://github.com/smh997/
"""
import math
n = int(input())
s = 0
for i in range(n):
    x,y = map(int, input().split())
    d = math.sqrt(x ** 2 + y ** 2)
    if d <= 10:
        s += 10
    elif d <= 30:
        s += 9
    elif d <= 50:
        s += 8
    elif d <= 70:
        s += 7
    elif d <= 90:
        s += 6
    elif d <= 110:
        s += 5
    elif d <= 130:
        s += 4
    elif d <= 150:
        s += 3
    elif d <= 170:
        s += 2
    elif d <= 190:
        s += 1
print(s)
