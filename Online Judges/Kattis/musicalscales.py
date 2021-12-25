"""
https://open.kattis.com/problems/musicalscales
Author: https://github.com/smh997/
"""
li = ['A', 'A#', 'B', 'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#']
m = [2, 2, 1, 2, 2, 2, 1]
mp = []
for i in range(12):
    lis = [li[i]]
    s = i
    for a in m:
        s = (s + a) % 12
        lis.append(li[s])
    mp.append(lis)
res = []
n = int(input())
inp = input().split()
for i in range(12):
    flag = True
    for ch in inp:
        if ch not in mp[i]:
            flag = False
            break
    if flag:
        res.append(li[i])
print(' '.join(res) if len(res) else 'none')
