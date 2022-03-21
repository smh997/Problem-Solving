"""
https://quera.org/contest/assignments/39254/problems/134886
Author: https://github.com/smh997/
"""
area = [False] * 51
n = int(input())
for i in range(n):
    s, e = map(int, input().split())
    for a in range(s, e+1):
        area[a] = True
sa = int(input())
ea = int(input())
flag = True
for a in range(sa, ea+1):
    if not area[a]:
        flag = False
        break
print('true' if flag else 'false')
