"""
https://open.kattis.com/problems/moderatepace
Author: https://github.com/smh997/
"""

n = int(input())
li = [list(map(int, input().split())) for i in range(3)]
ans = [str(sorted([li[0][i], li[1][i], li[2][i]])[1]) for i in range(n)]
print(' '.join(ans))