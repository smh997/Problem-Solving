"""
Author https://github.com/smh997/
https://open.kattis.com/problems/tictactoesolver
"""

li = [[ch for ch in input()] for _ in range(3)]
for i in range(3):
    if li[i][0] == li[i][1] == li[i][2] and li[i][0] != 'E':
        print(li[i][0])
        exit(0)
    if li[0][i] == li[1][i] == li[2][i] and li[0][i] != 'E':
        print(li[0][i])
        exit(0)
    if li[0][0] == li[1][1] == li[2][2] and li[0][0] != 'E':
        print(li[0][0])
        exit(0)
    if li[0][2] == li[1][1] == li[2][0] and li[0][2] != 'E':
        print(li[0][2])
        exit(0)
print('N')
