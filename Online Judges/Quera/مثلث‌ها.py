"""
https://quera.org/problemset/3561/
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(4 * n + 1):
    print(' ' * (4 * n - i), end='')
    if not i % 4:
        print('*' * (8 * (i // 4) + 1))
    else:
        for j in range(i // 4 + 1):
            print('*' + ' ' * (2 * (i % 4) - 1) + '*', end='')
            if j != i // 4:
                print(' ' * (6 - (2 * (i % 4) - 1)), end='')
        print()
