"""
https://open.kattis.com/problems/icpcawards
Author: https://github.com/smh997/
"""
n = int(input())
li = []
for i in range(n):
    a, b = input().split()
    if a not in li:
        print(a, b)
        li.append(a)
        if len(li) == 12:
            break