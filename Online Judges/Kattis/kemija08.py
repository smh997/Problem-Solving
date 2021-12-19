"""
https://open.kattis.com/problems/kemija08
Author: https://github.com/smh997/
"""
li = input().split()
for a in li:
    ind = 0
    res = ''
    while ind < len(a):
        if a[ind] in ['a', 'e', 'i', 'o', 'u']:
            res += a[ind]
            ind += 3
            continue
        res += a[ind]
        ind += 1
    print(res, end=' ')
print()
