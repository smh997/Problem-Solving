"""
https://open.kattis.com/problems/nop
Author: https://github.com/smh997/
"""
s = input()
c = 0
for i in range(len(s)):
    if ord(s[i]) <= ord('Z') and (i+c) % 4:
        c += 4 - ((i+c) % 4)
print(c)
