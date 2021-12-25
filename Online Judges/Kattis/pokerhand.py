"""
https://open.kattis.com/problems/pokerhand
Author: https://github.com/smh997/
"""
d = {'A': 0, '2': 0, '3': 0, '4': 0, '5': 0, '6': 0, '7': 0, '8': 0, '9': 0, 'T': 0, 'J': 0, 'Q': 0, 'K': 0}
li = input().split()
for a in li:
    d[a[0]] += 1
print(max(d.values()))