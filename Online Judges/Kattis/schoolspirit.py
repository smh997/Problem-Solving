"""
https://open.kattis.com/problems/schoolspirit
Author: https://github.com/smh997/
"""
n = int(input())
li = [0]
su = [0]
for i in range(1, n+1):
    a = int(input())
    li.append(a)
    su.append(su[i-1] + a * 0.8 ** (i-1))
print(su[n]*0.2)
s = 0
for i in range(1, n+1):
    s += su[i-1]
    for j in range(i+1, n+1):
        s += li[j] * 0.8 ** (j-2)
print(s * 0.2 / n)
