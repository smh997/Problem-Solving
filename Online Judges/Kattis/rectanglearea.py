"""
https://open.kattis.com/problems/rectanglearea
Author: https://github.com/smh997/
"""

li = list(map(float, input().split()))
print(abs(li[3]-li[1]) * abs(li[2]-li[0]))