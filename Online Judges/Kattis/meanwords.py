"""
https://open.kattis.com/problems/meanwords
Author: https://github.com/smh997/
"""

n = int(input())
w = [input() for _ in range(n)]
i = 0
ans = []
while True:
    res = [0, 0]
    f = True
    for word in w:
        if i >= len(word):
            continue
        f = False
        res = [res[0] + ord(word[i]), res[1] + 1]
    if f:
        break
    ans.append(chr(res[0]//res[1]))
    i += 1
print(''.join(ans))