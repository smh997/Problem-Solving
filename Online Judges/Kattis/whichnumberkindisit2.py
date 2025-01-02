"""
https://open.kattis.com/problems/whichnumberkindisit2
Author: https://github.com/smh997/
"""

t = int(input())
for i in range(t):
    n = int(input())
    s = int(n ** (0.5)) * int(n ** (0.5)) == n
    o = n % 2
    print('OS' if o and s else 'O' if o else 'S' if s else 'EMPTY')