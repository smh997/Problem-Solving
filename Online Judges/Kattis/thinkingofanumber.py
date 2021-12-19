"""
https://open.kattis.com/problems/thinkingofanumber
Author: https://github.com/smh997/
"""
while True:
    n = int(input())
    if not n:
        break
    lo = 1
    hi = int(1e9)
    div = []
    for i in range(n):
        s = input()
        if s.startswith('less than') and hi > int(s[10:]):
            hi = int(s[10:])
        elif s.startswith('greater than') and lo < int(s[13:]) + 1:
            lo = int(s[13:]) + 1
        elif s.startswith('divisible by') and int(s[13:]) not in div:
            div.append(int(s[13:]))
    if hi == int(1e9):
        print('infinite')
    else:
        res = []
        for i in range(lo, hi):
            b = True
            for d in div:
                if i % d:
                    b = False
            if b:
                res.append(str(i))
        print(' '.join(res) if len(res) else 'none')
