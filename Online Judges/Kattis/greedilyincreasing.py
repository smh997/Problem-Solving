"""
https://open.kattis.com/problems/greedilyincreasing
Author: https://github.com/smh997/
"""
n = int(input())
li = list(map(int, input().split()))
c = 1
res = [li[0]]
a = 0
for i in range(1, len(li)):
    if li[i] > li[a]:
        c += 1
        a = i
        res.append(li[i])
print(c)
for i in res:
    print(i, end=' ')
