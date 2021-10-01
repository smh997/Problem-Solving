"""
https://open.kattis.com/problems/drinkingsong
Author: https://github.com/smh997/
"""
n = int(input())
s = input()
for i in reversed(range(1, n+1)):
    if i > 1:
        print(str(i), 'bottles of', s, 'on the wall,', str(i), 'bottles of', s, end='')
        print('.')
        if i - 1 > 1:
            print('Take one down, pass it around,', str(i - 1), 'bottles of', s, 'on the wall.')
        else:
            print('Take one down, pass it around,', str(i - 1), 'bottle of', s, 'on the wall.')
    else:
        print(str(i), 'bottle of', s, 'on the wall,', str(i), 'bottle of', s, end='')
        print('.')
        print('Take it down, pass it around, no more bottles of', s, end='')
        print('.')
    print()
