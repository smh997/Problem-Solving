"""
https://open.kattis.com/problems/erase
Author: https://github.com/smh997/
"""
n = int(input())
s = input()
t = input()
tt = ''.join([str(1 - int(i)) for i in t])
print('Deletion succeeded' if (n % 2 and s == tt) or (not n % 2 and s == t) else 'Deletion failed')
