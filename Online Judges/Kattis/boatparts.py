"""
https://open.kattis.com/problems/boatparts
Author: https://github.com/smh997/
"""
p, n = map(int, input().split())
li = []
for i in range(n):
    a = input()
    if a not in li:
        li.append(a)
    if len(li) == p:
        print(i+1)
        exit(0)
print('paradox avoided')