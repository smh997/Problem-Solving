"""
https://open.kattis.com/problems/mylla2
Author: https://github.com/smh997/
"""

li = [[ch for ch in input()] for i in range(3)]
f = False
for i in range(3):
    if li[i][0] == li[i][1] == li[i][2] == 'O':
        f = True
        break
    if li[0][i] == li[1][i] == li[2][i] == 'O':
        f = True
        break
print('Jebb' if f or (li[0][0] == li[1][1] == li[2][2] == 'O') or (li[2][0] == li[1][1] == li[0][2] == 'O') else 'Neibb')
    