"""
https://quera.org/problemset/72875/
Author: https://github.com/smh997/
"""
n, li = int(input()), list(map(int, input().split()))
for i in range(1, n - 1):
    if li[i - 1] < li[i] > li[i + 1]:
        print('Ey baba :(')
        exit(0)
print('Bah Bah! Ajab jooji!')
