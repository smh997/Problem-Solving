"""
https://open.kattis.com/problems/mia
Author: https://github.com/smh997/
"""
while True:
    a, b, c, d = map(int, input().split())
    if a == 0:
        break
    if (a, b) == (1, 2) or (a, b) == (2, 1):
        if (c, d) == (1, 2) or (c, d) == (2, 1):
            print('Tie.')
        else:
            print('Player 1 wins.')
    elif (c, d) == (1, 2) or (c, d) == (2, 1):
        print('Player 2 wins.')
        continue
    elif a == b:
        if c == d:
            if a > c:
                print('Player 1 wins.')
            elif a < c:
                print('Player 2 wins.')
            else:
                print('Tie.')
        else:
            print('Player 1 wins.')
    elif c == d:
        print('Player 2 wins.')
    else:
        first = max(a, b) * 10 + min(a, b)
        second = max(c, d) * 10 + min(c, d)
        if first > second:
            print('Player 1 wins.')
        elif first < second:
            print('Player 2 wins.')
        else:
            print('Tie.')