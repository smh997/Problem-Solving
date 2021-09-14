"""
https://open.kattis.com/problems/battlesimulation
Author: https://github.com/smh997/
"""
s = input()
it = 0
res = ['' for i in range(len(s))]
cnt = 0
while it < len(s):
    if len(s) - it >= 3:
        if ('L' == s[it] and 'B' == s[it+1] and 'R' == s[it+2]) or ('L' == s[it] and 'R' == s[it+1] and 'B' == s[it+2]) or ('R' == s[it] and 'L' == s[it+1] and 'B' == s[it+2]) or ('R' == s[it] and 'B' == s[it+1] and 'L' == s[it+2]) or ('B' == s[it] and 'L' == s[it+1] and 'R' == s[it+2]) or ('B' == s[it] and 'R' == s[it+1] and 'L' == s[it+2]):
            res[cnt] = 'C'
            it += 3
            cnt += 1
            continue
    if s[it] == 'R':
        res[cnt] = 'S'
    elif s[it] == 'B':
        res[cnt] = 'K'
    else:
        res[cnt] = 'H'
    it += 1
    cnt += 1
for i in range(cnt):
    print(res[i], end='')
print()