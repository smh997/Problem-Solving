"""
https://open.kattis.com/problems/quickbrownfox
Author: https://github.com/smh997/
"""
n = int(input())
li = [False for i in range(26)]
for i in range(n):
    s = input().lower()
    for j in range(26):
        li[j] = False
    for c in s:
        o = ord(c)-ord('a')
        if -1 < o < 26:
            li[o] = True
    if li.__contains__(False):
        print("missing", end=' ')
        for j, a in enumerate(li):
            if not a:
                print(chr(ord('a') + j), end='')
        print()
    else:
        print("pangram")



