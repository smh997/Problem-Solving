"""
https://open.kattis.com/problems/4thought
Author: https://github.com/smh997/
"""
op = ['+', '-', '*', '//']
mp = {}
for i in op:
    for j in op:
        for k in op:
            mp[eval('4'+i+'4'+j+'4'+k+'4')] = (i[0], j[0], k[0])
m = int(input())
for i in range(m):
    n = int(input())
    if n in mp:
        print('4', mp[n][0], '4', mp[n][1], '4', mp[n][2], '4 =', n)
    else:
        print('no solution')
