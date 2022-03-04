"""
https://quera.org/problemset/110019/
Author: https://github.com/smh997/
"""
trans = []
n = int(input())
for i in range(n):
    trans.append(input().split())
trans.sort(key=lambda x: x[2])
lo = 0
fail = 200001
dep_after_fail = 0
dep = 0
for tr in trans:
    if tr[0] == 'DEP':
        dep += int(tr[1])
    else:
        if tr[3] == 'OK':
            if dep < int(tr[1]):
                lo += int(tr[1]) - dep
                dep = 0
            else:
                dep -= int(tr[1])
st = lo
for tr in trans:
    if tr[0] == 'DEP':
        st += int(tr[1])
    else:
        if tr[3] == 'OK':
            if st < int(tr[1]):
                print('DOROGHE')
                exit(0)
            st -= int(tr[1])
        else:
            if st >= int(tr[1]):
                print('DOROGHE')
                exit(0)
print(lo)
