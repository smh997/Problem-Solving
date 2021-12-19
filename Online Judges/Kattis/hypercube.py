"""
https://open.kattis.com/problems/hypercube
Author: https://github.com/smh997/
"""
def gray_index(a):
    res, s = 0, 2
    for ch in reversed(a):
        if ch == '1':
            res = s - res - 1
        s <<= 1
    return res


n, a, b = input().split()
print(gray_index(b) - gray_index(a) - 1)