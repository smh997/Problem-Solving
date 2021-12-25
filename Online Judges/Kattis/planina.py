"""
https://open.kattis.com/problems/planina
Author: https://github.com/smh997/
"""
n = int(input())
si = 4
res = 4
sq = 1
for i in range(n):
	res += sq + si
	si = sq*4 + si*2
	sq *= 4
print(res)