"""
https://quera.org/problemset/82386/
Author: https://github.com/smh997/
"""
def inrange(i, j):
    return 0 <= i < 3 and 0 <= j < 3


def check(i, j):
    global grid
    return grid[i][j]


def backt(r, c, ins, ins_i):
    global mp, dirc, dirr, grid
    if ins_i == len(ins):
        return 1
    grid[r][c] = True
    cc = 0
    for l in range(1, 3):
        if inrange(r + l * dirr[mp[ins[ins_i]]], c + l * dirc[mp[ins[ins_i]]]):
            flag = False
            for kk in range(1, l):
                if check(r + kk * dirr[mp[ins[ins_i]]], c + kk * dirc[mp[ins[ins_i]]]):
                    flag = True
                    break
                else:
                    grid[r + kk * dirr[mp[ins[ins_i]]]][c + kk * dirc[mp[ins[ins_i]]]] = True
            if flag:
                break
            if check(r + l * dirr[mp[ins[ins_i]]], c + l * dirc[mp[ins[ins_i]]]):
                for kk in range(1, l):
                    grid[r + kk * dirr[mp[ins[ins_i]]]][c + kk * dirc[mp[ins[ins_i]]]] = False
                break
            ccc = backt(r + l * dirr[mp[ins[ins_i]]], c + l * dirc[mp[ins[ins_i]]], ins, ins_i+1)
            for kk in range(1, l):
                grid[r + kk * dirr[mp[ins[ins_i]]]][c + kk * dirc[mp[ins[ins_i]]]] = False
            cc += ccc
    grid[r][c] = False
    return cc


s = input()
mp = {'D': 0, 'R': 1, 'U': 2, 'L': 3}
dirr = [1, 0, -1, 0]
dirc = [0, 1, 0, -1]
grid = [[False for i in range(3)] for j in range(3)]
cc = 0
for i in range(3):
    for j in range(3):
        cc += backt(i, j, s, 0)
print(cc)