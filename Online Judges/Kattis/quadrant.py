"""
https://open.kattis.com/problems/quadrant
Author: https://github.com/smh997/
"""
x=int(input())
y=int(input())
if x>0:
    if y>0:
        print(1)
    else:
        print(4)
elif y>0:
    print(2)
else:
    print(3)