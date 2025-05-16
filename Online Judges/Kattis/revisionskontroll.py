"""
https://open.kattis.com/problems/revisionskontroll
Author: https://github.com/smh997/
"""

n = int(input())
li = list(map(int, input().split()))
ans = []
s = set()
for a in li:
    ans.append('0' if a in s else '1')
    s.add(a)
print(' '.join(ans))