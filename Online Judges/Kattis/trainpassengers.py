"""
https://open.kattis.com/problems/trainpassengers
Author: https://github.com/smh997/
"""
cap, n = map(int, input().split())
li = []
for i in range(n):
    left, enter, stay = map(int, input().split())
    li.append((left, enter, stay))
fillcap = 0
for i in range(n):
    left, enter, stay = li[i][0], li[i][1], li[i][2]
    if left > fillcap:
        print('impossible')
        exit(0)
    if fillcap-left+enter > cap:
        print('impossible')
        exit(0)
    if stay > 0 and fillcap-left+enter != cap:
        print('impossible')
        exit(0)

    fillcap = fillcap-left+enter
if fillcap != 0:
    print('impossible')
else:
    print('possible')