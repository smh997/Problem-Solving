"""
https://open.kattis.com/problems/conundrum
Author: https://github.com/smh997/
"""
inp = input().lower()
res = 0
for i in range(len(inp)):
	res = (res + 1)if inp[i]!='per'[i%3] else res
print(res)