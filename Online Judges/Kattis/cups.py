"""
https://open.kattis.com/problems/cups
Author: https://github.com/smh997/
"""
n = int(input())
li = {}
lis = []
for i in range(n):
    a, b = map(str, input().split())
    if not a.isalpha():
        li[int(a)//2] = b
        lis.append(int(a)//2)
    else:
        li[int(b)] = a
        lis.append(int(b))
lis.sort()
for a in lis:
    print(li[a])
