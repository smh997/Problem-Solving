"""
https://open.kattis.com/problems/hothike
Author: https://github.com/smh997/
"""
n = int(input())
li = list(map(int, input().split()))
t = 60
rl = 0
for i in range(n-2):
    if max(li[i], li[i+2]) < t:
        rl = i+1
        t = max(li[i], li[i+2])
print(rl, t)