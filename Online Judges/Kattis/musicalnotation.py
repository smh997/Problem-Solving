"""
https://open.kattis.com/problems/musicalnotation
Author: https://github.com/smh997/
"""
di = {'G': 0, 'F': 1, 'E': 2, 'D': 3, 'C': 4, 'B': 5, 'A': 6, 'g': 7, 'f': 8, 'e': 9, 'd': 10, 'c': 11, 'b': 12, 'a': 13}
grid = []
n = int(input())
notes = input().split()
leng = n - 1
for note in notes:
    leng += int(note[1:]) if len(note) > 1 else 1
cnt = True
for k in di:
    li = [k, ':', ' ']
    if cnt or k == 'c':
        li += [' ' for l in range(leng)]
    else:
        li += ['-' for l in range(leng)]
    grid.append(li)
    cnt = not cnt
it = 3
for note in notes:
    notee = note[0]
    dur = int(note[1:]) if len(note) > 1 else 1
    for i in range(it, it + dur):
        grid[di[notee]][i] = '*'
    it += dur + 1
for i in range(14):
    print(''.join(grid[i]))
