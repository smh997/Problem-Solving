"""
https://open.kattis.com/problems/prva
Author: https://github.com/smh997/
"""
r, c = map(int, input().split())
li = [input() for i in range(r)]
words = []
temp = []
for i in range(r):
    if '#' in li[i]:
        temp = li[i].split('#')
        for w in temp:
            if len(w) >= 2:
                words.append(w)
    else:
        words.append(li[i])
for j in range(c):
    ww = ''
    for i in range(r):
        ww += li[i][j]
    if '#' in ww:
        temp = ww.split('#')
        for w in temp:
            if len(w) >= 2:
                words.append(w)
    else:
        words.append(ww)
words.sort()
print(words[0])