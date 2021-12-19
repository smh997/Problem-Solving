"""
https://open.kattis.com/problems/harshadnumbers
Author: https://github.com/smh997/
"""
n = input()
while True:
	if int(n)%sum(list(map(int, n)))==0:
		print(n)
		break
	n = str(int(n)+1)