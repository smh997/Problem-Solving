"""
https://quera.org/problemset/106796/
Author: https://github.com/smh997/
"""
n = int(input())
k = int(input())
s = input()
for i in range(k):
    t = ''
    for c in range(0, n):
        t += chr(ord('a') + (((ord(s[c]) - ord('a')) + 1) % 26))
    s = t[-1] + t[0:n - 1]
print(s)
