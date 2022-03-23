"""
https://quera.org/problemset/102254/
Author: https://github.com/smh997/
"""
s = input()
ss = 'a'
while True:
    if s == ss:
        print(s)
        break
    ss = s
    s = []
    for i in range(10):
        if str(i) in ss:
            s += str(i)
            c = ss.count(str(i))
            if c > 1:
                s += str(c)
    s = ''.join(sorted(s))
