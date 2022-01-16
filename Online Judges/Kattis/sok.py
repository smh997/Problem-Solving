"""
https://open.kattis.com/problems/sok
Author: https://github.com/smh997/
"""
a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = min(a[0]/b[0],min(a[1]/b[1],a[2]/b[2]))
print(str(a[0]-c*b[0]) + ' ' + str(a[1]-c*b[1]) + ' ' + str(a[2]-c*b[2]))
