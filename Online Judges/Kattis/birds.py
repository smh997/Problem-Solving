"""
https://open.kattis.com/problems/birds
Author: https://github.com/smh997/
"""
l, d, n = map(int, input().split())
li = []
if l <12:
	print(0)
	exit(0)
for i in range(n):
	li.append(int(input()))
li.sort()
s = 6
res = 0
for i in range(n):
	res += (li[i]-s)//d
	s = li[i]+d
res += (l-6+d-s)//d
print(res)