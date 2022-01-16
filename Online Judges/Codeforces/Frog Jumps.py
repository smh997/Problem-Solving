"""
https://codeforces.com/contest/1324/problem/C
Author: https://github.com/smh997/
"""
t = int(input())
while t:
    s = 'R' + input() + 'R'
    m = 0
    rpos = 0
    for i in range(1, len(s)):
        if s[i] == 'R':
            m = max(m, i-rpos)
            rpos = i
    print(m)
    t -= 1