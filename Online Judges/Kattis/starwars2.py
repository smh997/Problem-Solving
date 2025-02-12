"""
https://open.kattis.com/problems/starwars2
Author: https://github.com/smh997/
"""

n = int(input())
li = sorted(list(map(int, input().split())))
print(' '.join(list(map(str, li[len(li)//3:2*len(li)//3] + li[:len(li)//3] + li[2*len(li)//3:]))))