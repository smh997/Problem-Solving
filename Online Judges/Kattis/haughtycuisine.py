"""
https://open.kattis.com/problems/haughtycuisine
Author: https://github.com/smh997/
"""

n = int(input())
li = [input().split() for i in range(n)]
print(li[0][0])
print('\n'.join(li[0][1:]))