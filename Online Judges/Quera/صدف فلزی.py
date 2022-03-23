"""
https://quera.org/problemset/6581/
Author: https://github.com/smh997/
"""
t, w = map(int, input().split())
print("%.04f" % (t / (1 - (1 / 2) ** w) / 2))