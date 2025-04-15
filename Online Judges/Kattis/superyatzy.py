"""
https://open.kattis.com/problems/superyatzy
Author: https://github.com/smh997/
"""

li = [0] * 6
n , m = map(int ,input().split())
for i in range(n):
    li[int(input())-1] += 1
for a in li:
    if a + m >= n:
        print('Ja')
        exit(0)
print('Nej')