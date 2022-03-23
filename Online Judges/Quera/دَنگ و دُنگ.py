"""
https://quera.org/problemset/127290/
Author: https://github.com/smh997/
"""
t = int(input())
for i in range(t):
    n, s, a = map(int, input().split())
    b = s + a * (n - 1)
    if b % n or a >= s:
        print('-1')
        continue
    print(b // n - a)
