"""
https://quera.org/problemset/6193/
Author: https://github.com/smh997/
"""
s = input()
lis = [0 for i in range(26)]
small = [True for j in range(len(s))]
for i, a in enumerate(s):
    if 'A' <= a <= 'Z':
        small[i] = False
        lis[ord(a) - ord('A')] += 1
    else:
        lis[ord(a) - ord('a')] += 1
for i, a in enumerate(s):
    if small[i]:
        print(chr(ord('a') + (lis[ord(a) - ord('a')] * (ord(a) - ord('a')) + 1) % 26), end='')
    else:
        print(chr(ord('A') + (lis[ord(a) - ord('A')] * (ord(a) - ord('A')) + 1) % 26), end='')
