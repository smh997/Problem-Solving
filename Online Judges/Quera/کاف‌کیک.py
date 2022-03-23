"""
https://quera.org/problemset/51866/
Author: https://github.com/smh997/
"""
n, k = map(int, input().split())
li = list(map(int, input().split()))
if k == 1:
    print(max(li))
elif k > 2:
    print(min(li))
else:
    mi = 100000000
    if n == 2:
        print(min(li))
        exit(0)
    for i in range(1, n):
        # print(i, max(li[:i]), max(li[i:]))
        mx = min(max(li[:i]), max(li[i:]))
        mi = min(mi, mx)
    print(mi)
