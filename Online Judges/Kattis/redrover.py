"""
https://open.kattis.com/problems/redrover
Author: https://github.com/smh997/
"""
s = input()
mi = len(s)
for i in range(len(s)-1):
    for j in range(i+1, len(s)):
        c = s.count(s[i: j+1])
        mi = min(mi, c + j - i + 1 + len(s) - (c * (j-i+1)))
print(mi)