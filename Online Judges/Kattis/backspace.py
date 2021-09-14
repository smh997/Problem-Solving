"""
https://open.kattis.com/problems/backspace
Author: https://github.com/smh997/
"""
s = input()
li = []
for a in s:
    if a == '<':
        if len(li) > 0:
            li.pop()
    else:
        li.append(a)
for a in li:
    print(a, end='')
