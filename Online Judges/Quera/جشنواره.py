"""
https://quera.org/problemset/104589/
Author: https://github.com/smh997/
"""
n = int(input())
mx = 1
for i in reversed(range(2, n)):
    if n % i == 0:
        mx = i
        break
print(mx)
