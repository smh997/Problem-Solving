"""
https://open.kattis.com/problems/insert
Author: https://github.com/smh997/
"""
C = [[0 for i in range(103)] for j in range(103)]


def calc():
    C[1][0] = C[1][1] = 1
    for i in range(2, 101):
        for j in range(0, 101):
            if j == 0:
                C[i][j] = 1
                continue
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];


nodes = []
calc()
while True:
    n = int(input())
    if not n:
        break
    li = list(map(int, input().split()))
    nodes.clear()
    for i in range(n):
        nodes.append([li[i], -1, -1, 0, 0])
    for i in range(1, n):
        tmp = 0
        while True:
            if li[i] >= nodes[tmp][0]:
                if nodes[tmp][2] == -1:
                    nodes[tmp][2] = i
                    nodes[tmp][4] = 1
                    break
                else:
                    nodes[tmp][4] += 1
                    tmp = nodes[tmp][2]
            else:
                if nodes[tmp][1] == -1:
                    nodes[tmp][1] = i
                    nodes[tmp][3] = 1
                    break
                else:
                    nodes[tmp][3] += 1
                    tmp = nodes[tmp][1]
    res = 1
    for i in range(n):
        if nodes[i][3] and nodes[i][4]:
            res *= C[nodes[i][3] + nodes[i][4]][nodes[i][4]]
    print(res)