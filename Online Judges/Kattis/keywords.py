"""
https://open.kattis.com/problems/keywords
Author: https://github.com/smh997/
"""
n = int(input())
setw = set()
for i in range(n):
    s = input().lower()
    ss = ''
    for ch in s:
        ss += ch if ch != '-' else ' '
    setw.add(ss)
print(len(setw))
