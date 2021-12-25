"""
https://open.kattis.com/problems/okviri
Author: https://github.com/smh997/
"""
s = input()
li = ['' for i in range(5)]
for j in range(len(s)):
    for i in range(5):
        a = ''
        if j % 3 == 2:
            if i == 0 or i == 4:
                a += '..*.'
            elif i == 1 or i == 3:
                a += '.*.*'
            else:
                a += '*.' + s[j] + '.'
        elif j > 0 and j % 3 == 0:
            if i == 0 or i == 4:
                a += '..#.'
            elif i == 1 or i == 3:
                a += '.#.#'
            else:
                a += '*.' + s[j] + '.'
        else:
            if i == 0 or i == 4:
                a += '..#.'
            elif i == 1 or i == 3:
                a += '.#.#'
            else:
                a += '#.' + s[j] + '.'
        li[i] += a
li[0] += '.'
li[1] += '.'
if len(s) % 3 == 0:
    li[2] += '*'
else:
    li[2] += '#'
li[3] += '.'
li[4] += '.'
for aa in li:
    print(aa)