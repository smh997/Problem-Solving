"""
https://open.kattis.com/problems/finalexam2
Author: https://github.com/smh997/
"""

n = int(input())
li = [input() for _ in range(n)]
print(len([li[i+1] for i in range(n-1) if li[i] == li[i+1]]))