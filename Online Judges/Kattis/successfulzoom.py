"""
Author https://github.com/smh997/
https://open.kattis.com/problems/successfulzoom
"""

n = int(input())
li = list(map(int, input().split()))
for k in range(1, (n+1)//2+1):
    f = True
    for i in range(2*k-1, n, k):
        if li[i] <= li[i-k]:
            f = False
            break
    if f:
        print(k)
        exit(0)
print("ABORT!")
