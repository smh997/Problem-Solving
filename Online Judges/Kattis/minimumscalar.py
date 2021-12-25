"""
https://open.kattis.com/problems/minimumscalar
Author: https://github.com/smh997/
"""
t = int(input())
for i in range(1, t+1):
    n = int(input())
    lis = sorted(list(map(int, input().split())), reverse= True)
    lis2 = sorted(list(map(int, input().split())))
    print('Case #%d: ' % i, end='')
    print(sum([lis[i]*lis2[i] for i in range(n)]))
