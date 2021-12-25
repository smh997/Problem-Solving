"""
https://open.kattis.com/problems/pet
Author: https://github.com/smh997/
"""
li = []
j, m = -1, -1
for i in range(5):
    li.append(sum(list(map(int, input().split()))))
    if li[i] > m:
        j, m = i, li[i]
print(j+1, m)
