"""
Author https://github.com/smh997/
https://open.kattis.com/problems/everysecond
"""

h, m, s = map(int, input().split(' : '))
hh, mm, ss = map(int, input().split(' : '))
if hh < h:
    print((hh * 3600 + mm * 60 + ss) + (24 * 3600 - (h * 3600 + m * 60 + s)))
elif hh == h and mm < m:
    print(24 * 3600 - (m * 60 + s - (mm * 60 + ss)))
elif hh == h and mm == m and ss < s:
    print(24 * 3600 - (s - ss))
else:
    print((hh * 3600 + mm * 60 + ss) - (h * 3600 + m * 60 + s))
