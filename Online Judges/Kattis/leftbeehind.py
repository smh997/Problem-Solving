"""
https://open.kattis.com/problems/leftbeehind
Author: https://github.com/smh997/
"""
while True:
    sw, so = map(int, input().split())
    if (sw, so) == (0, 0):
        break
    if sw + so == 13:
        print('Never speak again.')
    elif sw > so:
        print('To the convention.')
    elif sw < so:
        print('Left beehind.')
    else:
        print('Undecided.')
