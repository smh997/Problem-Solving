"""
https://open.kattis.com/problems/symmetricorder
Author: https://github.com/smh997/
"""
li1, li2 = list(), list()
c = 0
while True:
    n = int(input())
    if n == 0:
        break
    c += 1
    li1.clear()
    li2.clear()
    for i in range(n):
        if i % 2:
            li2.append(input())
        else:
            li1.append(input())
    print('SET', c)
    li1.extend(reversed(li2))
    for a in li1:
        print(a)

