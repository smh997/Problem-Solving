"""
https://quera.org/problemset/110014/
Author: https://github.com/smh997/
"""
al, ar = input().split()
bl, br = input().split()
print('YES' if al == ar or al == br or ar == bl or bl == br else 'NO')
