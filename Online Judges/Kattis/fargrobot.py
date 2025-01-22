"""
https://open.kattis.com/problems/fargrobot
Author: https://github.com/smh997/
"""

n = int(input())
s = input()
rgb = {'R': False, 'G': False, 'B': False}
ans = ''
for ch in s:
    if not n:
        break
    rgb[ch] = True
    if False not in rgb.values():
        ans += ch
        rgb = {'R': False, 'G': False, 'B': False}
        n -= 1
print(ans)