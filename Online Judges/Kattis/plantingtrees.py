"""
https://open.kattis.com/problems/plantingtrees
Author: https://github.com/smh997/
"""
n = int(input())
m = 0
li = list(map(int, input().split()))
for i, a in enumerate(sorted(li, reverse= True)):
    m = max(m, a+i+2)
print(m)