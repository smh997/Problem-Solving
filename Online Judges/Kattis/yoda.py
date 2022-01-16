"""
https://open.kattis.com/problems/yoda
Author: https://github.com/smh997/
"""
n = input()
m = input()
sn = len(n)
sm = len(m)
s = max(sn, sm)
nn = ''
mm = ''
if sn < sm:
    n = '0'*(sm - sn) + n
if sm < sn:
    m = '0' * (sn - sm) + m
for i in range(s):
    a = int(n[i])
    b = int(m[i])
    if a == b:
        nn += n[i]
        mm += m[i]
    elif a < b:
        mm += m[i]
    else:
        nn += n[i]
if nn == '':
    print('YODA')
else:
    print(int(nn))
if mm == '':
    print('YODA')
else:
    print(int(mm))
