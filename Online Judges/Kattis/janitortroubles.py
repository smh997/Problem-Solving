"""
https://open.kattis.com/problems/janitortroubles
Author: https://github.com/smh997/
"""
li = list(map(int, input().split()))
s = sum(li)/2
print(((s-li[0])*(s-li[1])*(s-li[2])*(s-li[3]))**0.5)