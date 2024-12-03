"""
https://open.kattis.com/problems/ruffians
Author: https://github.com/smh997/
"""

t = int(input())
row = [[], []]
for _ in range(t):
    row[0] = list(map(int, input().split()))
    row[1] = list(map(int, input().split()))
    ans = False
    for i in range(2):
        for j in range(5):
            if row[i][j] in row[1-i][:j] or row[i][j] in row[1-i][j+1:]:
                ans = True
                break
    print('YES' if ans else 'NO')
