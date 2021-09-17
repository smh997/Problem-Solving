"""
https://open.kattis.com/problems/catalansquare
Author: https://github.com/smh997/
"""

Cat = [0] * 5001


def calc():
    global Cat
    Cat[0] = 1
    for i in range(1, 5001):
        Cat[i] = (4*i-2) * Cat[i-1] // (i+1)


calc()
n = int(input())
res = 0
for j in range(n+1):
    res += Cat[j] * Cat[n-j]
print(res)