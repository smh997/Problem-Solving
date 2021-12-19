"""
https://open.kattis.com/problems/joiningflows
Author: https://github.com/smh997/
"""
k = int(input())
fac = []
minf, maxf, minv = 0, 0, 0
for i in range(k):
    ti, ai, bi = map(int, input().split())
    fac.append((ti, ai, bi))
    minf += ai
    maxf += bi
    minv += ai * ti
fac1 = fac.copy()
fac2 = fac.copy()
fac1.sort()
fac2.sort(reverse=True)
r = int(input())
for i in range(r):
    temp, flow = map(int, input().split())
    if not minf <= flow <= maxf:
        print('no')
        continue
    remflow = flow - minf
    curalow = curahigh = minv
    for f in fac1:
        if not remflow:
            break
        val = min(remflow, f[2]-f[1])
        remflow -= val
        curalow += val*f[0]
    remflow = flow - minf
    for f in fac2:
        if not remflow:
            break
        val = min(remflow, f[2]-f[1])
        remflow -= val
        curahigh += val*f[0]
    if curalow <= temp*flow <= curahigh:
        print('yes')
    else:
        print('no')
