"""
https://quera.org/problemset/4068/
Author: https://github.com/smh997/
"""
n, k = map(int, input().split())
l = [1]
a = 1
if n / 2 < k:
    print("Impossible")
else:
    a = n // 2 + 1
    for i in range(n):
        print("%d " % a, end='')
        if i % 2 == 0:
            a -= n // 2
        else:
            a += n // 2 + 1