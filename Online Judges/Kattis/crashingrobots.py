"""
https://open.kattis.com/problems/crashingrobots
Author: https://github.com/smh997/
"""
def inboard(c, r, x, y):
    return 0 <= x < c and 0 <= y < r


t = int(input())
di = {'N': 0, 'E': 1, 'S': 2, 'W': 3}
for i in range(t):
    c, r = map(int, input().split())
    n, m = map(int, input().split())
    grid = [[-1 for j in range(r)] for k in range(c)]
    robot = []
    for rb in range(n):
        x, y, d = map(str, input().split())
        x, y = int(x)-1, int(y)-1
        robot.append([x, y, di[d]])
        grid[x][y] = rb
    flag = False
    for ins_i in range(m):
        rid, ins, rep = map(str, input().split())
        if flag:
            continue
        rid, rep = int(rid)-1, int(rep)
        if ins == 'L':
            rep %= 4
            robot[rid][2] = (robot[rid][2] - rep + 4) % 4
        elif ins == 'R':
            rep %= 4
            robot[rid][2] = (robot[rid][2] + rep) % 4
        else:
            if robot[rid][2] == 0:
                for step_i in range(1, rep+1):
                    if inboard(c, r, robot[rid][0], robot[rid][1]+step_i):
                        if grid[robot[rid][0]][robot[rid][1]+step_i] != -1:
                            print('Robot %d crashes into robot %d' % (rid+1, grid[robot[rid][0]][robot[rid][1]+step_i]+1))
                            flag = True
                            break
                    else:
                        print('Robot %d crashes into the wall' % (rid+1))
                        flag = True
                        break
                if flag:
                    continue
                grid[robot[rid][0]][robot[rid][1]] = -1
                robot[rid][1] = robot[rid][1] + rep
                grid[robot[rid][0]][robot[rid][1]] = rid
            elif robot[rid][2] == 1:
                for step_i in range(1, rep+1):
                    if inboard(c, r, robot[rid][0]+step_i, robot[rid][1]):
                        if grid[robot[rid][0]+step_i][robot[rid][1]] != -1:
                            print('Robot %d crashes into robot %d' % (rid+1, grid[robot[rid][0]+step_i][robot[rid][1]]+1))
                            flag = True
                            break
                    else:
                        print('Robot %d crashes into the wall' % (rid+1))
                        flag = True
                        break
                if flag:
                    continue
                grid[robot[rid][0]][robot[rid][1]] = -1
                robot[rid][0] = robot[rid][0] + rep
                grid[robot[rid][0]][robot[rid][1]] = rid
            elif robot[rid][2] == 2:
                for step_i in range(1, rep+1):
                    if inboard(c, r, robot[rid][0], robot[rid][1]-step_i):
                        if grid[robot[rid][0]][robot[rid][1]-step_i] != -1:
                            print('Robot %d crashes into robot %d' % (rid+1, grid[robot[rid][0]][robot[rid][1]-step_i]+1))
                            flag = True
                            break
                    else:
                        print('Robot %d crashes into the wall' % (rid+1))
                        flag = True
                        break
                if flag:
                    continue
                grid[robot[rid][0]][robot[rid][1]] = -1
                robot[rid][1] = robot[rid][1] - rep
                grid[robot[rid][0]][robot[rid][1]] = rid
            elif robot[rid][2] == 3:
                for step_i in range(1, rep+1):
                    if inboard(c, r, robot[rid][0]-step_i, robot[rid][1]):
                        if grid[robot[rid][0]-step_i][robot[rid][1]] != -1:
                            print('Robot %d crashes into robot %d' % (rid+1, grid[robot[rid][0]-step_i][robot[rid][1]]+1))
                            flag = True
                            break
                    else:
                        print('Robot %d crashes into the wall' % (rid+1))
                        flag = True
                        break
                if flag:
                    continue
                grid[robot[rid][0]][robot[rid][1]] = -1
                robot[rid][0] = robot[rid][0] - rep
                grid[robot[rid][0]][robot[rid][1]] = rid
    if not flag:
        print('OK')