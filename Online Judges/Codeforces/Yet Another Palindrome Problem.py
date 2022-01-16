"""
https://codeforces.com/contest/1324/problem/B
Author: https://github.com/smh997/
"""
t = int(input())
while t:
    n = int(input())
    li = list(map(int, input().split()))
    for i in range(1, n-1):
        if set(li[0:i]).intersection(set(li[i+1:])):
            print('YES')
            break
    else:
        print('NO')
    t -= 1
 