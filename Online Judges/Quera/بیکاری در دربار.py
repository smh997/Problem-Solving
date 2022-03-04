"""
https://quera.org/problemset/8939/
Author: https://github.com/smh997/
"""
import re
inp = input()
A, p, B, e, C = map(str, inp.split())
if not A.isdigit():
    s = A
    res = int(C) - int(B)
elif not B.isdigit():
    s = B
    res = int(C) - int(A)
else:
    s = C
    res = int(A) + int(B)


ss = re.sub("#", "(\d)+", s)
s = re.search(ss,str(res))
if s == None:
    print(-1)
else:
    s = s.group()
    inp = re.sub("(\d)*#(\d)*", s, inp)
    print(inp)