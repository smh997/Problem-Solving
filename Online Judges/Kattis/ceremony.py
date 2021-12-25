"""
https://open.kattis.com/problems/ceremony
Author: https://github.com/smh997/
"""
n = int(input())
li = list(map(int, input().split()))
m = n
li.sort()
for i in range(len(li)):
    m = min(m, li[i]+n-i-1)
print(m)