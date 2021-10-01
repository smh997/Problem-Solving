"""
https://open.kattis.com/problems/differentdistances
Author: https://github.com/smh997/
"""
while True:
    inp = input()
    if inp == '0':
        break
    x1, y1, x2, y2, p = map(float, inp.split())
    print('%.5f' % ((abs(x1-x2)**p + abs(y1-y2)**p)**(1/p)))