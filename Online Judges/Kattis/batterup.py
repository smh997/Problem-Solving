"""
https://open.kattis.com/problems/batterup
Author: https://github.com/smh997/
"""
n = int(input())
li = list(map(int, input().split()))
d = 0
sum = 0
for a in li:
    if a != -1:
        d += 1
        sum += a
print(sum/d)