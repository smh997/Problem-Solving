"""
https://open.kattis.com/problems/cetiri
Author: https://github.com/smh997/
"""
li = sorted(list(map(int, input().split())))
if li[1] - li[0] == li[2] - li[1]:
    print(li[2] + li[2] - li[1])
elif li[1] - li[0] < li[2] - li[1]:
    print(li[1] + li[1] - li[0])
else:
    print(li[0] + li[2] - li[1])