"""
https://open.kattis.com/problems/bannord
Author: https://github.com/smh997/
"""

s, m = input(), input().split()
ans = []
for w in m:
    forbidden = False
    for ch in s:
        if ch in w:
            forbidden = True
    ans.append('*' * len(w) if forbidden else w)
print(' '.join(ans))