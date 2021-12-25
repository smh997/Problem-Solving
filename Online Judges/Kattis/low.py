"""
https://open.kattis.com/problems/low
Author: https://github.com/smh997/
"""
n, k = map(int, input().split())
li = list(map(int, input().split()))
li.sort()
lo = li[1] - li[0]
hi = li[(2*n*k)-1] - li[0]
res = lo
mid = 0
while lo <= hi:
    mid = (lo+hi)//2
    c, u = 0, 0
    i = 0
    while i < 2*n*k-1:
        if li[i+1] - li[i] <= mid:
            c += 1
            u += 2
            i += 1
        else:
            u += 1
        if (u > 2*c*k) or (c == n):
            break
        i += 1
    if c == n:
        res = mid
        hi = mid - 1
    else:
        lo = mid + 1
print(res)
