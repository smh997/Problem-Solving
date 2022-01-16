"""
https://open.kattis.com/problems/easiest
Author: https://github.com/smh997/
"""
while True:
	n = int(input())
	if not n:
		break
	s = sum([int(a) for a in str(n)])
	i = 11
	while True:
		if sum([int(a) for a in str(n*i)]) == s:
			print(i)
			break
		i+=1