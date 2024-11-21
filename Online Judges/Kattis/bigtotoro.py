"""
https://open.kattis.com/problems/bigtotoro
Author: https://github.com/smh997/
"""

n, k = map(int, input().split())
s = list(map(int, input().split()))
z = sum([a for a in s if a % 4 == 0])
d = [-1, -1, -1, -1]
for a in s:
    d[a % 4] = max(a, d[a % 4])
while k % 4:
    if d[k % 4] == -1:
        print(k)
        exit(0)
    k += d[k % 4]
print(k + z)