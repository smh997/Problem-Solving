"""
https://quera.org/problemset/3417/
Author: https://github.com/smh997/
"""
li = [0 for i in range(1000999)]
t = int(input())
for a in range(999990):
    s = sum(map(int, str(a))) + a
    li[s] = 1
for j in range(t):
    b = int(input())
    if li[b] == 1:
        print("Yes")
    else:
        print("No")
