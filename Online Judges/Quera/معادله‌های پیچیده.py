"""
https://quera.org/problemset/52547/ 
Author: https://github.com/smh997/
"""
import math


def bmm(p, q):
    g = math.gcd(p, q)
    return p // g, q // g


n = int(input())
s = input()
left, right = s.split('=')
leftx = 0
rightx = 0
leftp = 0
rightp = 0
ind = 0
leftstart = True
if left[0] == '-':
    leftstart = False
    ind = 1
for i in range(ind, len(left)):
    if left[i] in ['+', '-']:
        if 'x' in left[ind:i]:
            if len(left[ind:i]) == 1:
                leftx += -1 if not leftstart else 1
            else:
                leftx += -int(left[ind:i - 1]) if not leftstart else int(left[ind:i - 1])
        else:
            leftp += int(left[ind:i]) if leftstart else -int(left[ind:i])
        leftstart = True if left[i] == '+' else False
        ind = i + 1
    if i == len(left) - 1:
        if 'x' in left[ind:]:
            if len(left[ind:]) == 1:
                leftx += -1 if not leftstart else 1
            else:
                leftx += -int(left[ind:i]) if not leftstart else int(left[ind:i])
        else:
            leftp += int(left[ind:]) if leftstart else -int(left[ind:])

ind = 0
rightstart = True
if right[0] == '-':
    rightstart = False
    ind = 1
for i in range(ind, len(right)):
    if right[i] in ['+', '-']:
        if 'x' in right[ind:i]:
            if len(right[ind:i]) == 1:
                rightx += -1 if not rightstart else 1
            else:
                rightx += -int(right[ind:i - 1]) if not rightstart else int(right[ind:i - 1])
        else:
            rightp += int(right[ind:i]) if rightstart else -int(right[ind:i])
        rightstart = True if right[i] == '+' else False
        ind = i + 1
    if i == len(right) - 1:
        if 'x' in right[ind:]:
            if len(right[ind:]) == 1:
                rightx += -1 if not rightstart else 1
            else:
                rightx += -int(right[ind:i]) if not rightstart else int(right[ind:i])
        else:
            rightp += int(right[ind:]) if rightstart else -int(right[ind:])
if rightx == leftx:
    print('invalid')
    exit(0)
a, b = bmm(rightp - leftp, leftx - rightx)
if b < 0:
    b *= -1
    a *= -1
print(a, b)
