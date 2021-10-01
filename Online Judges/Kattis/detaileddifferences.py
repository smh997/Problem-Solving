"""
https://open.kattis.com/problems/detaileddifferences
Author: https://github.com/smh997/
"""
n = int(input())
for j in range(n):
	a = input()
	b = input()
	print(a)
	print(b)
	for i in range(len(a)):
		print('.' if a[i]==b[i] else '*', end='')
	print('\n' if j<n-1 else '' )