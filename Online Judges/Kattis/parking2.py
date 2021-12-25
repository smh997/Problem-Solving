"""
https://open.kattis.com/problems/parking2
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    k = int(input())
    li = list(map(int, input().split()))
    print((max(li) - min(li)) * 2)
