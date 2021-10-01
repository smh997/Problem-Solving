"""
https://open.kattis.com/problems/fbiuniversal
Author: https://github.com/smh997/
"""
val = '0123456789ACDEFHJKLMNPRTVWX'
mp = {'B': '8', 'G': 'C', 'I': '1', 'O': '0', 'Q': '0', 'S': '5', 'U': 'V', 'Y': 'V', 'Z': '2'}
di = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, 'A': 10, 'C': 11, 'D': 12, 'E': 13, 'F': 14, 'H': 15, 'J': 16, 'K': 17, 'L': 18, 'M': 19, 'N': 20, 'P': 21, 'R': 22, 'T': 23, 'V': 24, 'W': 25, 'X': 26}


def calc(s):
    global mp, di
    ss = ''
    for a in s:
        if a in mp:
            ss += mp[a]
        else:
            ss += a
    return (2 * di[ss[0]] + 4 * di[ss[1]] + 5 * di[ss[2]] + 7 * di[ss[3]] + 8 * di[ss[4]] + 10 * di[ss[5]] + 11 * di[ss[6]] + 13 * di[ss[7]]) % 27


p = int(input())
for i in range(p):
    k, s = map(str, input().split())
    if val[calc(s)] != s[-1]:
        print(k, 'Invalid')
    else:
        ss = ''
        for a in s:
            if a in mp:
                ss += mp[a]
            else:
                ss += a
        res = 0
        for j in range(8):
            res += di[ss[j]] * 27 ** (7 - j)
        print(k, res)
