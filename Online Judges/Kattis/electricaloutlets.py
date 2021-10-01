"""
https://open.kattis.com/problems/electricaloutlets
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    li = list(map(int, input().split()))
    print(sum(li[1:]) - (li[0]-1))