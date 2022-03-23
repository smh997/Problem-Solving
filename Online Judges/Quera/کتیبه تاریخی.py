"""
https://quera.org/problemset/49589/
Author: https://github.com/smh997/
"""
n, m = map(int, input().split())
li, res = [], 0
for i in range(n):
    li.append(input())
for i in range(n - 3):
    for j in range(m - 1):
        for k in range(2, min(m - j + 1, ((n - i) // 2) + 1)):
            flag = True
            for f in range(2 * k):
                if li[i + f][j] == '.':
                    flag = False
                    break
            if not flag:
                continue
            for f in range(k):
                if li[i + (2 * k - 1)][j + f] == '.':
                    flag = False
                    break
            if flag:
                res += 1
print(res)