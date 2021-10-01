"""
https://open.kattis.com/problems/bubbletea
Author: https://github.com/smh997/
"""
n = int(input())
tea = list(map(int, input().split()))
m = int(input())
topp = list(map(int, input().split()))
mi = 1e10
for i in range(n):
    li = list(map(int, input().split()))
    for j in (li[1:]):
        mi = min(tea[i] + topp[j-1], mi)
money = int(input())
print(max(0, (money // mi) - 1))
