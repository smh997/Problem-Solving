"""
https://quera.org/problemset/82380/
Author: https://github.com/smh997/
"""
n = int(input())
res = 0
s = set()
for i in range(n):
    email = input()
    if email.count('@') != 1:
        continue
    email = email.lower()
    username, dom = email.split('@')

    if username.startswith('.') or username.endswith('.') or username.count('..') > 0:
        continue
    if dom.startswith('.') or dom.endswith('.') or dom.count('..') > 0 or not (3 <= len(dom) <= 30):
        continue
    us = ''
    flag = False
    for a in username:
        if a != '.':
            us += a
            if not (ord('a') <= ord(a) <= ord('z') or ord('0') <= ord(a) <= ord('9') or a == '_'):
                flag = True
                break
    if flag:
        continue
    if not (6 <= len(us) <= 30):
        continue
    for a in dom:
        if a != '.':
            if not (ord('a') <= ord(a) <= ord('z') or ord('0') <= ord(a) <= ord('9') or a == '-'):
                flag = True
                break
    if flag:
        continue
    s.add(us + '@' + dom)
print(len(s))