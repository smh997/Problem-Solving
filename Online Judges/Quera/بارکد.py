"""
https://quera.org/problemset/52544/
Author: https://github.com/smh997/
"""
li = []
for i in range(9):
    li.append(input())
check1 = [li[1][0], li[1][2], li[1][6], li[1][8], li[7][0], li[7][2], li[7][6], li[7][8]]
check0 = [li[1][1], li[1][7], li[7][1], li[7][7]]
if '0' in li[0][:3] or '0' in li[0][6:] or '0' in li[2][:3] or '0' in li[2][6:] or '0' in li[6][:3]  or'0' in li[6][6:] or '0' in li[8][:3]  or'0' in li[8][6:] or '0' in check1 or '1' in check0:
    print(0)
    exit(0)
res = 1
for i in range(3):
    for j in range(3,6):
        if li[i][j] == '2':
            res *= 2
for i in range(6, 9):
    for j in range(3, 6):
        if li[i][j] == '2':
            res *= 2
for i in range(3, 6):
    for j in range(9):
        if li[i][j] == '2':
            res *= 2
print(res)