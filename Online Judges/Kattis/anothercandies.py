"""
https://open.kattis.com/problems/anothercandies
Author: https://github.com/smh997/
"""
t = int(input())
for i in range(t):
    _ = input()
    n = int(input())
    res = 0
    for j in range(n):
        res += int(input())
    print('NO' if res % n else 'YES')
