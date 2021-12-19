"""
https://open.kattis.com/problems/irrationaldivision
Author: https://github.com/smh997/
"""
a, b = map(int, input().split())
if a % 2 and b % 2:
    print(1)
elif (not a % 2) and (not b % 2):
    print(0)
else:
    if a % 2 == 0:
        print(0)
    elif a < b:
        print(2)
    else:
        print(0)