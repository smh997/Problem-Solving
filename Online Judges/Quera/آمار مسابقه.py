"""
https://quera.org/problemset/17678/
Author: https://github.com/smh997/
"""
n, d = map(int, input().split())
lop = {}
lod = [[] for i in range(1, d + 1)]
lis = [[0, 0, 0] for i in range(1, d+1)]

for i in range(n):
    inp = input()[2:-2]
    li = inp.split(" | ")
    day = int(li[0][5:]) - 1
    time = li[1][6:]
    name = li[2][6:]
    if name not in lod[day]:
        lod[day].append(name)
        lis[day][0] += 1
        if name not in lop.keys():
            lis[day][1] += 1
        lop[name] = day

for a in lop.keys():
    lis[lop[a]][2] += 1
for a in lis:
    print(a[0], a[1], a[2])
