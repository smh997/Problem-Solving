"""
https://open.kattis.com/problems/grazedgrains
Author: https://github.com/smh997/
"""
def incircle(i, j):
    global circles
    for c in circles:
        if (i - c[0]) ** 2 + (j - c[1]) ** 2 <= c[2] ** 2:
            return True
    return False


circles = []
n = int(input())
for i in range(n):
    x, y, r = map(int, input().split())
    circles.append((x * 20, y * 20, r * 20))
res = 0
for i in range(-200, 400):
    for j in range(-200, 400):
        if incircle(i, j):
            res += 1
print('%.4f' % (res / 400))
