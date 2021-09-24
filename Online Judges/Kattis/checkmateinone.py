"""
https://open.kattis.com/problems/checkmateinone
Author: https://github.com/smh997/
"""
li = []
kr, kh = 0, 0
KR, KH = 0, 0
RR, RH = 0, 0

for i in range(8):
    li.append(input())
    for j in range(8):
        if li[i][j] == 'k':
            kr, kh = i, j
        elif li[i][j] == 'K':
            KR, KH = i, j
        elif li[i][j] == 'R':
            RR, RH = i, j

if kr == 0: # and kh not in [0, 7]:
    if KR == kr + 2 and KH == kh:
        if RH not in [kh-1, kh, kh+1]:
            print('Yes')
            exit(0)
if kr == 7: # and kh not in [0, 7]:
    if KR == kr - 2 and KH == kh:
        if RH not in [kh-1, kh, kh+1]:
            print('Yes')
            exit(0)
if kh == 0: #and kr not in [0, 7]:
    if KH == kh + 2 and KR == kr:
        if RR not in [kr-1, kr, kr+1]:
            print('Yes')
            exit(0)
if kh == 7: #and kr not in [0, 7]:
    if KH == kh - 2 and KR == kr:
        if RR not in [kr-1, kr, kr+1]:
            print('Yes')
            exit(0)
if (kr, kh) == (0, 0):
    if KR == 1 and KH == 2:
        if RR >= 2:
            print('Yes')
            exit(0)
    elif KR == 2 and KH == 1:
        if RH >= 2:
            print('Yes')
            exit(0)
if (kr, kh) == (0, 7):
    if KR == 1 and KH == 5:
        if RR >= 2:
            print('Yes')
            exit(0)
    elif KR == 2 and KH == 6:
        if RH < 6:
            print('Yes')
            exit(0)
if (kr, kh) == (7, 0):
    if KR == 5 and KH == 1:
        if RH >= 2:
            print('Yes')
            exit(0)
    elif KR == 6 and KH == 2:
        if RR < 6:
            print('Yes')
            exit(0)
if (kr, kh) == (7, 7):
    if KR == 5 and KH == 6:
        if RH < 6:
            print('Yes')
            exit(0)
    elif KR == 6 and KH == 5:
        if RR < 6:
            print('Yes')
            exit(0)
print('No')
