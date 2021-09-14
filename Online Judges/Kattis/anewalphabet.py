"""
https://open.kattis.com/problems/anewalphabet
Author: https://github.com/smh997/
"""
d = ['@', '8', '(', '|)', '3', '#', '6', '[-]', '|', '_|', '|<', '1',
     '[]\\/[]', '[]\\[]', '0', '|D', '(,)', '|Z', '$', '\'][\'', '|_|', '\\/', '\\/\\/', '}{', '`/', '2']
s = input()
for c in s:
    c = c.lower()
    inx = ord(c)-ord('a')
    if 0 <= inx <= 25:
        print(d[inx], end='')
    else:
        print(c, end='')
