"""
https://open.kattis.com/problems/barcelona
Author: https://github.com/smh997/
"""

n, k = map(int, input().split())
li = list(map(int, input().split()))
ans = li.index(k)+1
print('fyrst' if ans == 1 else 'naestfyrst' if ans == 2 else f'{ans} fyrst')