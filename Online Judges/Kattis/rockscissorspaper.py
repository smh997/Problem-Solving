"""
https://open.kattis.com/problems/rockscissorspaper
Author: https://github.com/smh997/
"""
dir = [(1, 0), (0, 1)]


def inrange(ii, jj, rr, cc):
    return 0 <= ii < rr and 0 <= jj < cc


t = int(input())
for i in range(t):
    r, c, n = map(int, input().split())
    grid = []
    for j in range(r):
        grid.append([a for a in input()])
    for _ in range(n):
        newgrid = []
        for jjj in range(r):
            newgrid.append(grid[jjj].copy())
        for f in range(r):
            for g in range(c):
                for d in dir:
                    if inrange(f+d[0], g+d[1], r, c):
                        if grid[f][g] == 'R' and grid[f+d[0]][g+d[1]] == 'P':
                            newgrid[f][g] = 'P'
                        elif grid[f][g] == 'R' and grid[f+d[0]][g+d[1]] == 'S':
                            newgrid[f+d[0]][g+d[1]] = 'R'
                        elif grid[f][g] == 'S' and grid[f+d[0]][g+d[1]] == 'P':
                            newgrid[f+d[0]][g+d[1]] = 'S'
                        elif grid[f][g] == 'S' and grid[f+d[0]][g+d[1]] == 'R':
                            newgrid[f][g] = 'R'
                        elif grid[f][g] == 'P' and grid[f+d[0]][g+d[1]] == 'R':
                            newgrid[f+d[0]][g+d[1]] = 'P'
                        elif grid[f][g] == 'P' and grid[f+d[0]][g+d[1]] == 'S':
                            newgrid[f][g] = 'S'
        grid = newgrid
    for rr in range(r):
        print(''.join(grid[rr]))
    print()
