"""
https://open.kattis.com/problems/secondopinion
Author: https://github.com/smh997/
"""

s = int(input())
print(s // 3600, ":", (s % 3600) // 60, ":", (s % 3600) % 60)