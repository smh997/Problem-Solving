"""
https://open.kattis.com/problems/fimmtudagstilbod
Author: https://github.com/smh997/
"""
x = int(input())
print(1000 if x <= 2020 else 1000 + (x - 2020) * 100)