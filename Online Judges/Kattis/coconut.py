"""
https://open.kattis.com/problems/coconut
Author: https://github.com/smh997/
"""
s, n = map(int, input().split())
m = n
s -= 1
li = [[2, i+1] for i in range(n)]
it = 0
while len(li) > 1:
    it = (it + s) % len(li)
    if li[it][0]:
        li[it][0] -= 1
        if li[it][0] == 1:
            li.insert(it, [1, li[it][1]])
        else:
            it = (it + 1) % len(li)
    else:
        li.pop(it)
print(li[0][1])
