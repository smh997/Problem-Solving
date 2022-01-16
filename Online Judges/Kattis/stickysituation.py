"""
https://open.kattis.com/problems/stickysituation
Author: https://github.com/smh997/
"""
n = int(input())
li = list(map(int, input().split()))
li.sort()
for i in range(n-2):
    for j in range(i+1, n-1):
        if li[i]+li[j] > li[j+1]:
            print('possible')
            exit(0)
print('impossible')