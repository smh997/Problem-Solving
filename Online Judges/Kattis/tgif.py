"""
https://open.kattis.com/problems/tgif
Author: https://github.com/smh997/
"""
mon = {'JAN': 0, 'FEB': 1, 'MAR': 2, 'APR': 3, 'MAY': 4, 'JUN': 5, 'JUL': 6, 'AUG': 7, 'SEP': 8, 'OCT': 9, 'NOV': 10, 'DEC': 11}
day = {'MON': 0, 'TUE': 1, 'WED': 2, 'THU': 3, 'FRI': 4, 'SAT': 5, 'SUN': 6}
sumdays = [31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365]
d, m = map(str, input().split())
fj = input()
dd = int(d)
mm = mon[m]
ff = day[fj]
if mm <= 1:
    if mm == 0:
        if (dd + ff) % 7 == 5:
            print('TGIF')
        else:
            print(':(')
    else:
        if (sumdays[0] + dd + ff) % 7 == 5:
            print('TGIF')
        else:
            print(':(')
else:
    if (sumdays[mm-1] + dd + ff) % 7 == 5 or (sumdays[mm-1] + dd + ff + 1) % 7 == 5:
        print('not sure')
    else:
        print(':(')
