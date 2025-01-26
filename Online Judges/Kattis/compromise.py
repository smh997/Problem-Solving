"""
https://open.kattis.com/problems/compromise
Author: https://github.com/smh997/
"""

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    li = [input() for i in range(n)]
    a = ""
    for j in range(m):
        c = 0
        for i in range(n):
            if li[i][j] == '1':
                c += 1
        a += "1" if c >= (n // 2 + 1) else "0"
    print(a)