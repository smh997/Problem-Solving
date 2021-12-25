"""
https://open.kattis.com/problems/oktalni
Author: https://github.com/smh997/
"""
di = {'000': 0, '001': 1, '010': 2, '011': 3, '100': 4, '101': 5, '110': 6, '111': 7}
s = input()
if len(s) % 3:
    s = '0'*(3 - len(s) % 3) + s
for i in range(0, len(s), 3):
    print(di[s[i:i+3]], end='')
print()