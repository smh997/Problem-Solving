"""
https://open.kattis.com/problems/heartrate
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    b, p = map(float, input().split())
    print('%.4f %.4f %.4f' % (60 / (p / (b-1)), 60 * b / p, 60 * b / p + (60 * b / p - (60/(p/(b-1))))))