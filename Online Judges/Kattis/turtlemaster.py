"""
https://open.kattis.com/problems/turtlemaster
Author: https://github.com/smh997/
"""
grid = []
dir = [(0, 1), (1, 0), (0, -1), (-1, 0)]


def inrange(r, c):
    return 0 <= r <= 7 and 0 <= c <= 7


for i in range(8):
    grid.append([ch for ch in input()])
inst = input()
curp = (7, 0)
curf = 0
for it, ins in enumerate(inst):
    if ins == 'F':
        if inrange(curp[0] + dir[curf][0], curp[1] + dir[curf][1]):
            if grid[curp[0] + dir[curf][0]][curp[1] + dir[curf][1]] in ['C', 'I']:
                print('Bug!')
                exit(0)
            if grid[curp[0] + dir[curf][0]][curp[1] + dir[curf][1]] == 'D':
                if it == len(inst)-1:
                    print('Diamond!')
                    exit(0)
                else:
                    curp = (curp[0] + dir[curf][0], curp[1] + dir[curf][1])
            else:
                curp = (curp[0] + dir[curf][0], curp[1] + dir[curf][1])
        else:
            print('Bug!')
            exit(0)
    elif ins == 'R':
        curf = (curf + 1) % 4
    elif ins == 'L':
        curf = (curf + 3) % 4
    else:
        if inrange(curp[0] + dir[curf][0], curp[1] + dir[curf][1]):
            if grid[curp[0] + dir[curf][0]][curp[1] + dir[curf][1]] != 'I':
                print('Bug!')
                exit(0)
            else:
                grid[curp[0] + dir[curf][0]][curp[1] + dir[curf][1]] = '.'
        else:
            print('Bug!')
            exit(0)
print('Bug!')
