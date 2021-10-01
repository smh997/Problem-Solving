"""
https://open.kattis.com/problems/earlywinter
Author: https://github.com/smh997/
"""
n, d = map(int, input().split())
li = list(map(int, input().split()))
i = 0
while i != n:
    if li[i] <= d:
        break
    i += 1
print('It hadn\'t snowed this early in %d years!' % i if i != n else 'It had never snowed this early!')