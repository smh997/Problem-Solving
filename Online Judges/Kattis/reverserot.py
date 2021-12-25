"""
https://open.kattis.com/problems/reverserot
Author: https://github.com/smh997/
"""
li = [chr(a) for a in range(ord('A'), ord('Z')+1)] + ['_', '.']
while True:
    s = input()
    if s == '0':
        break
    f, a = s.split()
    f = int(f)
    res = ''
    for ch in reversed(a):
        res += li[(li.index(ch) + f) % 28]
    print(res)