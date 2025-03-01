"""
https://open.kattis.com/problems/npuzzle
Author: https://github.com/smh997/
"""

li = []
inp = []
ans = 0
for i in range(4):
    inp.append(input())
    for j in range(4):
        li.append((i, j))
for i in range(4):
    for j in range(4):
        if inp[i][j] != '.':
            p = li[ord(inp[i][j]) - ord('A')]
            ans += abs(p[0] - i) + abs(p[1] - j)
print(ans)