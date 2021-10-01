"""
https://open.kattis.com/problems/eatingout
Author: https://github.com/smh997/
"""
li = list(map(int, input().split()))
print('possible' if sum(li[1:]) <= 2*li[0] else 'impossible')