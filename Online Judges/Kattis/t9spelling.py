"""
https://open.kattis.com/problems/t9spelling
Author: https://github.com/smh997/
"""
di = [' ', '', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
al = {' ': 0, 'a': 2, 'b': 2, 'c': 2, 'd': 3, 'e': 3, 'f': 3, 'g': 4, 'h': 4, 'i': 4, 'j': 5, 'k': 5, 'l': 5, 'm': 6, 'n': 6, 'o': 6, 'p': 7, 'q': 7, 'r': 7, 's': 7, 't': 8, 'u': 8, 'v': 8, 'w': 9, 'x': 9, 'y': 9, 'z': 9}
t = int(input())
for i in range(t):
    s, pre = input(), 1
    print('Case #%d: ' % (i+1), end='')
    for a in s:
        print((' ' if al[a] == pre else '') + (di[al[a]].index(a)+1)*str(al[a]), end='')
        pre = al[a]
    print()

