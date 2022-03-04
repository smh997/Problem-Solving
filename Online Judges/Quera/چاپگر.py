"""
https://quera.org/problemset/64434/
Author: https://github.com/smh997/
"""
n, m = map(int, input().split())
for i in range(3 * n):
    for j in range(3 * m):
        if i // n % 2:
            if j // m % 2:
                print('X', end='')
            else:
                print('.', end='')
        else:
            if j // m % 2:
                print('.', end='')
            else:
                print('X', end='')
    print()
