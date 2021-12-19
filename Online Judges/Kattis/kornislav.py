"""
https://open.kattis.com/problems/kornislav
Author: https://github.com/smh997/
"""
li = list(map(int, input().split()))
li.remove(max(li))
print(min(li)*max(li))