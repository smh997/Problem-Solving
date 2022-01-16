"""
https://open.kattis.com/problems/tictactoe2
Author: https://github.com/smh997/
"""

def win(lis: list, ch):
    for i in range(3):
        if lis[i].count(ch) == 3:
            return True
        fl = True
        for j in range(3):
            if lis[j][i] != ch:
                fl = False
                break
        if fl:
            return True
    if [lis[0][0], lis[1][1], lis[2][2]].count(ch) == 3 or [lis[0][2], lis[1][1], lis[2][0]].count(ch) == 3:
        return True
    return False


n = int(input())
for i in range(n):
    li = []
    x, o, d = 0, 0, 0
    for j in range(3):
        li.append(input())
        x += li[j].count('X')
        o += li[j].count('O')
        d += li[j].count('.')
    if x not in [o, o+1] or d + x + o != 9:
        print('no')
    elif win(li, 'X'):
        print('no' if win(li, 'O') or x != o+1 else 'yes')
    elif win(li, 'O'):
        print('no' if x != o else 'yes')
    else:
        print('yes')
    if i == n-1:
        break
    input()
