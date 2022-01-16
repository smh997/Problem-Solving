"""
https://codeforces.com/contest/1324/problem/A
Author: https://github.com/smh997/
"""
t = int(input())
while t:
    n = int(input())
    li = list(map(int, input().split()))
    m = max(li)
    flag = True
    for a in li:
        if (m - a) % 2 != 0:
            print('NO')
            flag = False
            break
    if not flag:
        t -= 1
        continue
    print('Yes')
    t -= 1