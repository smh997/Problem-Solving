"""
https://open.kattis.com/problems/knotknowledge
Author: https://github.com/smh997/
"""
n = int(input())
li = list(map(int, input().split()))
delli = list(map(int, input().split()))
for d in delli:
    li.remove(d)
print(li[0])