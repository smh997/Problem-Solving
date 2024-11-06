"""
https://open.kattis.com/problems/maeting
Author: https://github.com/smh997/
"""

n, m = map(int, input().split())
mondayList = input().split()
wednesdayList = input().split()
ans = []
for a in mondayList:
    if a in wednesdayList:
        ans.append(a)
print(' '.join(ans))