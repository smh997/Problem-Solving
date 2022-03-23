"""
https://quera.org/problemset/123803/
Author: https://github.com/smh997/
"""

consume = 0
lamps = []
peles = []

n = int(input())
for i in range(n):
    lamp = tuple(map(str, input().split()))
    lamps.append(lamp)
status = [[False, 0] for i in range(n)]
k = int(input())
for i in range(k):
    e, p = map(int, input().split())
    peles.append((e, p))
m = int(input())
for i in range(m):
    l_id, day, fultime = map(str, input().split())
    l_id = int(l_id)
    day = int(day)
    hh, mm, ss = map(int, fultime.split(':'))
    time = day * 24 * 60 * 60 + hh * 60 * 60 + mm * 60 + ss
    if status[l_id - 1][0]:
        if lamps[l_id - 1][0] == 'SWITCH':
            consume += (time - status[l_id - 1][1]) * int(lamps[l_id - 1][1])
            status[l_id - 1][0] = False
        else:
            if status[l_id - 1][1] + int(lamps[l_id - 1][2]) <= time:
                consume += int(lamps[l_id - 1][2]) * int(lamps[l_id - 1][1])
                status[l_id - 1][1] = time
            else:
                consume += (time - status[l_id - 1][1]) * int(lamps[l_id - 1][1])
                status[l_id - 1][1] = time
    else:
        status[l_id - 1] = [True, time]
time = 31 * 24 * 60 * 60 + 23 * 60 * 60 + 59 * 60 + 59
for i in range(n):
    if status[i][0]:
        if lamps[i][0] == 'SWITCH':
            consume += (time - status[i][1]) * int(lamps[i][1])
            status[i][0] = False
        else:
            if status[i][1] + int(lamps[i][2]) <= time:
                consume += int(lamps[i][2]) * int(lamps[i][1])
                status[i][1] = time
            else:
                consume += (time - status[i][1]) * int(lamps[i][1])
                status[i][1] = time
for i in range(k):
    if peles[i][0] >= consume:
        res = peles[i][1] * consume
        break
print(res)