"""
https://open.kattis.com/problems/bestbefore
Author: https://github.com/smh997/
"""
dayof = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
inp = input()
s = list(map(int, inp.split('/')))
s.sort()

y = s[0] + 2000 if s[0] < 2000 else s[0]
if 1 <= s[1] <= 12:
    flag = False
    if s[1] == 2:
        if 1 <= s[2] <= (29 if (y % 4 == 0 and y % 100 != 0) or (y % 4 == 0 and y % 100 == 0 and y % 400 == 0) else 28):
            print('%4d-%02d-%02d' % (y, s[1], s[2]))
            exit(0)
    else:
        if 1 <= s[2] <= dayof[s[1]]:
            print('%4d-%02d-%02d' % (y, s[1], s[2]))
            exit(0)
if 1 <= s[2] <= 12:
    flag = False
    if s[2] == 2:
        if 1 <= s[1] <= (29 if (y % 4 == 0 and y % 100 != 0) or (y % 4 == 0 and y % 100 == 0 and y % 400 == 0) else 28):
            print('%4d-%02d-%02d' % (y, s[2], s[1]))
            exit(0)
    else:
        if 1 <= s[1] <= dayof[s[2]]:
            print('%4d-%02d-%02d' % (y, s[2], s[1]))
            exit(0)

y = s[1] + 2000 if s[1] < 2000 else s[1]
if 1 <= s[0] <= 12:
    flag = False
    if s[0] == 2:
        if 1 <= s[2] <= (29 if (y % 4 == 0 and y % 100 != 0) or (y % 4 == 0 and y % 100 == 0 and y % 400 == 0) else 28):
            print('%4d-%02d-%02d' % (y, s[0], s[2]))
            exit(0)
    else:
        if 1 <= s[2] <= dayof[s[0]]:
            print('%4d-%02d-%02d' % (y, s[0], s[2]))
            exit(0)
if 1 <= s[2] <= 12:
    flag = False
    if s[2] == 2:
        if 1 <= s[0] <= (29 if (y % 4 == 0 and y % 100 != 0) or (y % 4 == 0 and y % 100 == 0 and y % 400 == 0) else 28):
            print('%4d-%02d-%02d' %(y, s[2], s[0]))
            exit(0)
    else:
        if 1 <= s[1] <= dayof[s[2]]:
            print('%4d-%02d-%02d' % (y, s[2], s[1]))
            exit(0)

y = s[2] + 2000 if s[2] < 2000 else s[2]
if 1 <= s[0] <= 12:
    flag = False
    if s[0] == 2:
        if 1 <= s[1] <= (29 if (y % 4 == 0 and y % 100 != 0) or (y % 4 == 0 and y % 100 == 0 and y % 400 == 0) else 28):
            print('%4d-%02d-%02d' % (y, s[0], s[1]))
            exit(0)
    else:
        if 1 <= s[1] <= dayof[s[0]]:
            print('%4d-%02d-%02d' % (y, s[0], s[1]))
            exit(0)
if 1 <= s[1] <= 12:
    flag = False
    if s[1] == 2:
        if 1 <= s[0] <= (29 if (y % 4 == 0 and y % 100 != 0) or (y % 4 == 0 and y % 100 == 0 and y % 400 == 0) else 28):
            print('%4d-%02d-%02d' % (y, s[1], s[0]))
            exit(0)
    else:
        if 1 <= s[0] <= dayof[s[1]]:
            print('%4d-%02d-%02d' % (y, s[1], s[0]))
            exit(0)
print(inp, 'is illegal')