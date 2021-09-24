"""
https://open.kattis.com/problems/cetvrta
Author: https://github.com/smh997/
"""
a, b = list(), list()
for i in range(3):
	x, y = map(int, input().split())
	if x in a:
		a.remove(x)
	else:
		a.append(x)
	if y in b:
		b.remove(y)
	else:
		b.append(y)
print(a[0], b[0])