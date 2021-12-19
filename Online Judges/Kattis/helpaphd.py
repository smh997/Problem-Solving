"""
https://open.kattis.com/problems/helpaphd
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    inp = input()
    if inp == 'P=NP':
        print('skipped')
        continue
    a, b = map(int, inp.split('+'))
    print(a+b)