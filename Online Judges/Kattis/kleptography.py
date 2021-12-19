"""
https://open.kattis.com/problems/kleptography
Author: https://github.com/smh997/
"""
n, m = map(int, input().split())
p = input()
c = input()
for i in range(1, m+1):
    ch = chr(ord('a') + ((ord(c[-i]) - ord('a')) - (ord(p[-i]) - ord('a')) + 26) % 26)
    p = ch + p
print(p[n:n+m])