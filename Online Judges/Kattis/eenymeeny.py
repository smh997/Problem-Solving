"""
https://open.kattis.com/problems/eenymeeny
Author: https://github.com/smh997/
"""
s = len(input().split())
n = int(input())
li = []
for i in range(n):
    li.append(input())
a = []
b = []
p = 0
ind = True
while n:
    p = (p % n + s-1) % n
    temp = li[p]
    if ind:
        a.append(temp)
    else:
        b.append(temp)
    ind = not ind
    n -= 1
    li.remove(temp)
print(len(a))
for aa in a:
    print(aa)
print(len(b))
for aa in b:
    print(aa)
