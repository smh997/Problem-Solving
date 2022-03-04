"""
https://quera.org/problemset/28949/
Author: https://github.com/smh997/
"""
n = int(input())
li = []
for i in range(n):
    name, time, e = input().split()
    h, m = time.split(':')
    h = int(h)
    m = int(m)
    li.append((h * 100 + m, e))
li.sort()
count = 0
m = 0
ind = 0
for i in range(len(li)):
    if li[i][1] == '+':
        count += 1
    else:
        count -= 1
    if i < len(li) - 1 and li[i][0] != li[i + 1][0]:
        if count > m:
            m = count
            ind = i
print("%02d:%02d" % (li[ind][0] // 100, li[ind][0] % 100))

