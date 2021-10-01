"""
https://open.kattis.com/problems/8queens
Author: https://github.com/smh997/
"""
li = []
q = 0
queens = []
for i in range(8):
    li.append(input())
    q += li[i].count('*')
    for j in range(8):
        if li[i][j] == '*':
            queens.append((i, j))
if q != 8:
    print('invalid')
    exit(0)
for i in range(8):
    for j in range(i+1, 8):
        if queens[i][0] == queens[j][0] or queens[i][1] == queens[j][1] or abs(queens[i][0]-queens[j][0]) == abs(queens[i][1] - queens[j][1]):
            print('invalid')
            exit(0)
print('valid')