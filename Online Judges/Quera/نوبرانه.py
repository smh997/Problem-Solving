"""
https://quera.org/problemset/104588/
Author: https://github.com/smh997/
"""
a = list(map(int, input().split()))
res = 0
for aa in a:
    if aa >= 80:
        res += 1
if res >= 3:
    print('Mamma mia!')
elif res >= 1:
    print('Mamma mia!!')
else:
    print('Mamma mia!!!')
