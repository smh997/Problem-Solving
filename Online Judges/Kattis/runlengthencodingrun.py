"""
https://open.kattis.com/problems/runlengthencodingrun
Author: https://github.com/smh997/
"""
r, inp = map(str, input().split())
if r == 'D':
    ch, rep = '', 0
    for i in range(0, len(inp), 2):
        ch = inp[i]
        rep = int(inp[i+1])
        for j in range(rep):
            print(ch, end='')
    print()
else:
    ch, rep = '', 0
    for i in range(len(inp)):
        if inp[i] == ch:
            rep += 1
        elif ch != '':
            print(ch, end='')
            print(rep, end='')
            rep = 1
            ch = inp[i]
        else:
            ch = inp[i]
            rep = 1
        if i == len(inp) - 1:
            print(ch, end='')
            print(rep, end='')
    print()