"""
https://open.kattis.com/problems/trik
Author: https://github.com/smh997/
"""
li = [0, 1, 0, 0]
inp = input()
for a in inp:
    if a == 'A':
        (li[1], li[2]) = (li[2], li[1])
    elif a == 'B':
        (li[3], li[2]) = (li[2], li[3])
    else:
        (li[1], li[3]) = (li[3], li[1])
for i in range(1, len(li)):
    if li[i] == 1:
        print(i)
        break