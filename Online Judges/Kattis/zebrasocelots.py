"""
https://open.kattis.com/problems/zebrasocelots
Author: https://github.com/smh997/
"""
n = int(input())
s = ''
for i in range(n):
  if input()=='Z' :
    s+='0' 
  else:
    s += '1'
print(int(s, 2))