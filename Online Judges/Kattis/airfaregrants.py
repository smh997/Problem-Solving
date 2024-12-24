"""
https://open.kattis.com/problems/airfaregrants
Author: https://github.com/smh997/
"""

n = int(input())
li = [int(input()) for i in range(n)]
print(max(0, min(li) - max(li)//2))