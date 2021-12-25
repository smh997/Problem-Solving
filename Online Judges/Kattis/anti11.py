"""
https://open.kattis.com/problems/anti11
Author: https://github.com/smh997/
"""
li = [1, 2, 3]
mod = 1000000007
for i in range(3, 10001):
    li.append(((li[i-1] % mod)+(li[i-2] % mod)) % mod)
t = int(input())
for i in range(t):
    n = int(input())
    print(li[n])