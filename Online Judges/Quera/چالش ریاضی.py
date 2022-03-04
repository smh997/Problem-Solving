"""
https://quera.org/problemset/102258/
Author: https://github.com/smh997/
"""
li = []


def f(s: str, k: int, i: int, N: int):
    global li
    if i == N:
        li.append(s)
        return
    a = int(s[i - 1]) + k
    b = int(s[i - 1]) - k
    if a < 10:
        f(s + str(a), k, i + 1, N)
    if k != 0 and b > -1:
        f(s + str(b), k, i + 1, N)


n, k = map(int, input().split())
for i in range(1, 10):
    f(str(i), k, 1, n)
li.sort()
print(','.join(li))
