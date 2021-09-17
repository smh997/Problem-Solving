"""
https://open.kattis.com/problems/catalan
Author: https://github.com/smh997/
"""

Cat = [0] * 5001


def calc():
    global Cat
    Cat[0] = 1
    for i in range(1, 5001):
        Cat[i] = (4*i-2) * Cat[i-1]//(i+1)


calc()
q = int(input())
for j in range(q):
    x = int(input())
    print(Cat[x])
