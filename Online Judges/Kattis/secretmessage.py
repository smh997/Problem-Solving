"""
https://open.kattis.com/problems/secretmessage
Author: https://github.com/smh997/
"""
import math
n = int(input())
for i in range(n):
    s = input()
    le = len(s)
    k = int(math.ceil(math.sqrt(le)))
    m = k**2
    # print(m, le)
    s += (m-le) * '*'
    # print(s)
    for l in range(int(k)):
        for j in reversed(range(int(k))):
            if s[j*k+l] != '*':
                print(s[j*k+l], end='')
    print()