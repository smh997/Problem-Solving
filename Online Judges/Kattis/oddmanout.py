"""
https://open.kattis.com/problems/oddmanout
Author: https://github.com/smh997/
"""
N = int(input())
for i in range(N):
	g = int(input())
	li = list(map(int, input().split()))
	for a in li:
		if li.count(a)%2==1:
			print("Case #%d:" %(i+1), a)