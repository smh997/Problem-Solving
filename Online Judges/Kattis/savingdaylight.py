"""
https://open.kattis.com/problems/savingdaylight
Author: https://github.com/smh997/
"""
import sys


def dif_time_calculator(h1, m1, h2, m2):
    return (h2 - h1, m2 - m1) if m1 <= m2 else (h2 - h1 - 1, 60 + m2 - m1)


lines = sys.stdin.readlines()
for line in lines:
    date = line.split()
    h1, m1 = map(int, date[3].split(':'))
    h2, m2 = map(int, date[4].split(':'))
    h, m = dif_time_calculator(h1, m1, h2, m2)
    print(date[0], date[1], date[2], h, 'hours', m, 'minutes')
