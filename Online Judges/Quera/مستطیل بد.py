"""
https://quera.org/problemset/3541/
Author: https://github.com/smh997/
"""
n = int(input())
answer = 0
for a in range (1, (n // 3) + 1):
    answer += ((n - 3 * a) // 2) - max(0, n // 2 - 2 * a + 1) + 1
print(answer)
