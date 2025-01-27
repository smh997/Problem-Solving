"""
https://open.kattis.com/problems/champernowneverification
Author: https://github.com/smh997/
"""

n = input()
k = 1
for ch in n:
    if int(ch) == k:
        k += 1
    else:
        print(-1)
        exit(0)
print(k-1)