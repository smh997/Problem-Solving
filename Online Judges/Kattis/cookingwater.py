"""
https://open.kattis.com/problems/cookingwater
Author: https://github.com/smh997/
"""
n = int(input())
li = []
for i in range(n):
    a, b = map(int, input().split())
    li.append((a, b))
for i in range(1001):
    flag = True
    for interval in li:
        if not (interval[0] <= i <= interval[1]):
            flag = False
            break
    if flag:
        print('gunilla has a point')
        exit(0)
print('edward is right')