"""
https://open.kattis.com/problems/empleh
Author: https://github.com/smh997/
"""
white = input().split()
black = input().split()
grid = [[0 for i in range(8)] for j in range(8)]
if len(white) > 1:
    white = white[1].split(',')
    for w in white:
        if len(w) == 2:
            grid[8-(ord(w[1])-ord('0'))][ord(w[0]) - ord('a')] = 'P'
        else:
            grid[8 - (ord(w[2]) - ord('0'))][ord(w[1]) - ord('a')] = w[0]
else:
    white.clear()
if len(black) > 1:
    black = black[1].split(',')
    for w in black:
        if len(w) == 2:
            grid[8-(ord(w[1])-ord('0'))][ord(w[0]) - ord('a')] = 'p'
        else:
            grid[8 - (ord(w[2]) - ord('0'))][ord(w[1]) - ord('a')] = w[0].lower()
else:
    black.clear()
print('+---+---+---+---+---+---+---+---+')
flag = True
for i in range(8):
    print('|', end='')
    for j in range(8):
        if flag:
            print('.' + ('.' if grid[i][j] == 0 else grid[i][j]) + '.|', end='')
        else:
            print(':' + (':' if grid[i][j] == 0 else grid[i][j]) + ':|', end='')
        flag = not flag
    flag = not flag
    print()
    print('+---+---+---+---+---+---+---+---+')