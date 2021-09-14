"""
https://open.kattis.com/problems/avion
Author: https://github.com/smh997/
"""
f = True
for i in range(5):
  if 'FBI'  in  input():
    print(i+1, end=' ')
    f = False
if f:
  print('HE GOT AWAY!')