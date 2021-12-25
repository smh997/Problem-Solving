"""
https://open.kattis.com/problems/pripreme
Author: https://github.com/smh997/
"""
n = input()
li = list(map(int, input().split()))
a = sum(li)
b = max(li)
if b > (a-b):
    print(b*2)
else:
    print(a)
