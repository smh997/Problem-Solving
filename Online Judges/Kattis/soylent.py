"""
https://open.kattis.com/problems/soylent
Author: https://github.com/smh997/
"""
import math
t = int(input())
for i in range(t):
    print(math.ceil(int(input())/400))