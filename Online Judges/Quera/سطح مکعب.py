"""
https://quera.org/problemset/44072/
Author: https://github.com/smh997/
"""
v = int(input())
li = []
for i in range(1, v+1):
    if v % i == 0:
        li.append(i)
mx = 1000000000
for a in li:
    for b in li:
        if v % (a * b) == 0:
            c = v // (a * b)
            mx = min(2 * (a * b) + 2 * (b * c) + 2 * (a * c), mx)
print(mx)