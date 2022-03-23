"""
https://quera.org/problemset/138018/
Author: https://github.com/smh997/
"""
n = int(input())
li = []
for i in range(n):
    l, r = map(int, input().split())
    li.append((l, r))
li.sort()
l, r = -1, -1
arr = set()
for rang in li:
    if (l, r) == (-1, -1):
        l, r = rang[0], rang[1]
        continue
    if rang[0] <= r < rang[1]:
        r = rang[1]
    elif rang[0] > r:
        arr.add((l, r))
        l, r = rang[0], rang[1]
arr.add((l, r))
arr = sorted(list(arr))
one_flag, hundred_flag = True, True
for rang in arr:
    if rang[0] == 1 or rang[1] == 1:
        one_flag = False
    if rang[0] == 100 or rang[1] == 100:
        hundred_flag = False
if hundred_flag or one_flag:
    print(-1)
else:
    print(len(arr)-1)
