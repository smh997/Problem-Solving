"""
https://open.kattis.com/problems/jobexpenses
Author: https://github.com/smh997/
"""
n = int(input())
li = list(map(int, input().split()))
print(-sum([i for i in li if i<0]))