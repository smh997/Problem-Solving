"""
https://open.kattis.com/problems/missingnumbers
Author: https://github.com/smh997/
"""
n = int(input())
li = []
for i in range(n):
    a = int(input())
    li.append(a)
if n == li[n-1]:
    print('good job')
else:
    c = 1
    for a in li:
        if a != c:
            for i in range(c, a):
                print(i)
        c = a + 1
