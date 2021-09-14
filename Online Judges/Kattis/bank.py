"""
https://open.kattis.com/problems/bank
Author: https://github.com/smh997/
"""
n, t = map(int, input().split())
li = [False] * t
inp = []
for i in range(n):
    a, b = map(int, input().split())
    inp.append((a, b))
inp.sort(reverse=True)
res = 0
for i in range(n):
    j = inp[i][1]
    while j >= 0:
        if not li[j]:
            li[j] = True
            res += inp[i][0]
            break
        else:
            j -= 1
print(res)
