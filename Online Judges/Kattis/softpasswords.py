"""
https://open.kattis.com/problems/softpasswords
Author: https://github.com/smh997/
"""
s = input()
p = input()
res = ''
for a in p:
    res += a if a.isdigit() else a.upper() if a.islower() else a.lower()
if s == p or (len(p)+1 == len(s) and ((p == s[:len(s)-1] and s[len(s)-1].isdigit()) or (p == s[1:] and s[0].isdigit()))) or res == s:
    print('Yes')
else:
    print('No')
