"""
https://open.kattis.com/problems/vemvinner
Author: https://github.com/smh997/
"""

def check(ch, li):
    if li[0][0] == li[1][1] == li[2][2] == ch or li[0][2] == li[1][1] == li[2][0] == ch:
            return True
    for i in range(3):
        if li[i][0] == li[i][1] == li[i][2] == ch or li[0][i] == li[1][i] == li[2][i] == ch:
            return True
    return False
        
li = [input().split() for _ in range(3)]
print('Johan har vunnit' if check('X', li) else 'Abdullah har vunnit' if check('O', li) else 'ingen har vunnit')