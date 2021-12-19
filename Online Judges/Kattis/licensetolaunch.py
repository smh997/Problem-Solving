"""
https://open.kattis.com/problems/licensetolaunch
Author: https://github.com/smh997/
"""
n = int(input())
li = list(map(int, input().split()))
print(li.index(min(li)))
