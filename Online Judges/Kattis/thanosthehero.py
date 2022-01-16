"""
https://open.kattis.com/problems/thanosthehero
Author: https://github.com/smh997/
"""
n = int(input())
li = list(map(int, input().split()))
s = 0
for i in reversed(range(1, n)):
    if li[i-1] < li[i]:
        continue
    if li[i] == 0:
        print(1)
        exit(0)
    s += li[i-1] - li[i] + 1
    li[i-1] = li[i] - 1
print(s)