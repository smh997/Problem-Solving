"""
https://open.kattis.com/problems/jointjogjam
Author: https://github.com/smh997/
"""
ski, skj, soi, soj, eki, ekj, eoi, eoj = map(int, input().split())
print(max(((eoi - eki) ** 2 + (eoj - ekj) ** 2) ** 0.5, ((soi - ski) ** 2 + (soj - skj) ** 2) ** 0.5))