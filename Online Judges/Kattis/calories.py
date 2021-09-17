"""
https://open.kattis.com/problems/calories
Author: https://github.com/smh997/
"""
gtoc = [9, 4, 4, 4, 7]
sumcal = 0
sumfat = 0
flag = False
while True:
    li = input()
    if li == '-':
        if flag:
            break
        flag = True
        print('%d' % round((sumfat / sumcal * 100)), end='')
        print('%')
        sumfat, sumcal = 0, 0
        continue
    flag = False
    lis = li.split()
    fli = []
    for a in lis:
        fli.append((int(a[:len(a)-1]), a[-1]))
    perc = 0
    cal = 0
    for i in range(5):
        if fli[i][1] == 'g':
            fli[i] = (fli[i][0] * gtoc[i], 'C')
            cal += fli[i][0]
        elif fli[i][1] == 'C':
            cal += fli[i][0]
        else:
            perc += fli[i][0]
    realperc = 100 - perc
    realcal = cal * 100 / realperc
    sumcal += realcal
    if fli[0][1] == 'C':
        sumfat += fli[0][0]
    else:
        sumfat += fli[0][0] * realcal / 100
