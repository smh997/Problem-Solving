"""
https://open.kattis.com/problems/basketballoneonone
Author: https://github.com/smh997/
"""
s = input()
a, b = 0, 0
for i in range(0,len(s), 2):
  if s[i] == 'A' :
    a += int(s[i+1])
  else:
    b += int(s[i+1])
  if max(a, b)>=11:
    if a-b >= 2:
      print('A')
    elif b-a >= 2:
      print('B')
      