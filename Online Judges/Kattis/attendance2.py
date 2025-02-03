"""
https://open.kattis.com/problems/attendance2
Author: https://github.com/smh997/
"""

n = int(input())
ans = []
pre = ''
for i in range(n):
    tmp = input()
    if pre == '':
        pre = tmp
        continue
    if tmp != 'Present!':
        ans.append(pre)
        pre = tmp
    else:
        pre = ''
if pre != '':
    ans.append(pre)
if not ans:
    ans.append('No Absences')
print('\n'.join(ans))