"""
Author https://github.com/smh997/
https://open.kattis.com/problems/outlets
"""

n = int(input())
cords = list(filter(lambda x: x, [int(input()) for _ in range(n)]))
print(sum(cords) - len(cords) + 1)
