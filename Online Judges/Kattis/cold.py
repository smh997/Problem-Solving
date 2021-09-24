"""
https://open.kattis.com/problems/cold
Author: https://github.com/smh997/
"""
n = int(input())
print(len([a for a in list(map(int, input().split())) if a<0]))