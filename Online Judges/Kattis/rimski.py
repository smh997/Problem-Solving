"""
https://open.kattis.com/problems/rimski
Author: https://github.com/smh997/
"""
s = input()
dah, yek = '', ''
for a in s:
    if a in ['L', 'X', 'C']:
        dah += a
    else:
        yek += a
if yek == 'VI':
    yek = 'IV'
elif yek == 'I' and ((len(dah) > 0 and 'L' not in dah) or 'XX' in dah):
    yek = 'IX'
    dah = dah[:len(dah)-1]
if dah == 'LX':
    dah = 'XL'
print(dah + yek)
