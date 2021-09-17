"""
https://open.kattis.com/problems/candydivision
Author: https://github.com/smh997/
"""
n = int(input())
li = []
for i in range(1, int(n**0.5)+1):
    if n%i ==0:
        li.append(i-1)
        if n//i != i:
            li.append(n//i-1)
li.sort()
for a in li:
    print(a, end=' ')