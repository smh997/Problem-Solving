"""
https://open.kattis.com/problems/spavanac
Author: https://github.com/smh997/
"""
h, m = map(int, input().split())
print((h-1) % 24 if m < 45 else h, (m-45) % 60)
