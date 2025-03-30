"""
https://open.kattis.com/problems/smil
Author: https://github.com/smh997/
"""

s = input()
for i in range(len(s)):
    if i + 2 <= len(s):
        if ';)' == s[i:i+2] or s[i:i+2] == ':)':
            print(i)
    if i + 3 <= len(s):
        if ':-)' == s[i:i+3] or s[i:i+3] == ';-)':
            print(i)