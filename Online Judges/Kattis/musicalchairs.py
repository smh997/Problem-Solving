"""
https://open.kattis.com/problems/musicalchairs
Author: https://github.com/smh997/
"""
n = map(int, input().split())
li = list(map(int, input().split()))
li = [(li[i], i) for i in range(len(li))]
it = 0
c = li[it][0]
while len(li) > 1:
    it = (it + c - 1) % len(li)
    li.pop(it)
    it = it % len(li)
    c = li[it][0]
print(li[0][1]+1)
