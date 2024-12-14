"""
https://open.kattis.com/problems/stopwatch
Author: https://github.com/smh997/
"""

n = int(input())
li = [int(input()) for i in range(n)]
print('still running' if n % 2 else sum([li[i+1] - li[i] for i in range(0, n, 2)]))