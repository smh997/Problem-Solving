"""
https://open.kattis.com/problems/timebomb
Author: https://github.com/smh997/
"""
di = [
    ['***', '  *', '***', '***', '* *', '***', '***', '***', '***', '***'],
    ['* *', '  *', '  *', '  *', '* *', '*  ', '*  ', '  *', '* *', '* *'],
    ['* *', '  *', '***', '***', '***', '***', '***', '  *', '***', '***'],
    ['* *', '  *', '*  ', '  *', '  *', '  *', '* *', '  *', '* *', '  *'],
    ['***', '  *', '***', '***', '  *', '***', '***', '  *', '***', '***']
]

li = []
for i in range(5):
    li.append(input())
le = len(li[0])
digitnum = 1
if le > 3:
    digitnum += ((le - 3) // 4)
digits = ['' for i in range(digitnum*5)]
for i in range(digitnum):
    for j in range(5):
        digits[i * 5 + j] = li[j][i*4:i*4+3]
res = 0
for i in range(digitnum):
    flag = True
    for k in range(10):
        if (digits[i*5], digits[i*5+1], digits[i*5+2], digits[i*5+3], digits[i*5+4]) == (di[0][k], di[1][k], di[2][k], di[3][k], di[4][k]):
            flag = False
            res += k * (10**(digitnum-1-i))
            break
    if flag:
        print('BOOM!!')
        exit(0)
if res % 6:
    print('BOOM!!')
else:
    print('BEER!!')
