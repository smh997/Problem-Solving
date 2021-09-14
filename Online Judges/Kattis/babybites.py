"""
https://open.kattis.com/problems/babybites
Author: https://github.com/smh997/
"""
n = int(input())
li = input().split()
for i in range(1, n+1):
  if not(li[i-1]=='mumble' or int(li[i-1])==i):
    print('something is fishy')
    exit(0)
print('makes sense') 