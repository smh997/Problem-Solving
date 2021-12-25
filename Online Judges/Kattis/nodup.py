"""
https://open.kattis.com/problems/nodup
Author: https://github.com/smh997/
"""
li = []
for a in input().split():
    if a in li:
        print('no')
        exit(0)
    li.append(a)
print('yes')