"""
https://open.kattis.com/problems/romanholidays
Author: https://github.com/smh997/
"""
mp = {0: '', 1: 'I', 2: 'II', 3: 'III', 4: 'IV', 5: 'V', 6: 'VI', 7: 'VII', 8: 'VIII', 9: 'IX', 10: 'X',
      20: 'XX', 30: 'XXX', 40: 'XL', 50: 'L', 60: 'LX', 70: 'LXX', 80: 'LXXX', 90: 'XC', 100: 'C',
      200: 'CC', 300: 'CCC', 400: 'CD', 500: 'D', 600: 'DC', 700: 'DCC', 800: 'DCCC', 900: 'CM', 1000: 'M'}
for i in range(11, 1000):
    if i not in mp:
        str_i = str(i)
        s = ''
        for j in range(len(str_i)):
            s += mp[int(str_i[j])*10**(len(str_i)-1-j)]
        mp[i] = s
li = list(mp.values())[1:]
li.sort()
n = int(input())
for i in range(n):
    a = int(input())
    if a > 1000:
        m = a//1000
        a %= 1000
        ind = li.index(mp[a]) if a != 0 else -1
        if ind <= 945:
            print(ind+1 + m * 946)
        else:
            print(ind-1000 - m * 54)
    else:
        ind = li.index(mp[a])
        if ind <= 945:
            print(ind+1)
        else:
            print(ind-1000)
