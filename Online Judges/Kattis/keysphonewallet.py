"""
https://open.kattis.com/problems/keysphonewallet
Author: https://github.com/smh997/
"""

n = int(input())
li = [input() for _ in range(n)]
ans = [item for item in ['keys', 'phone', 'wallet'] if item not in li]
print('\n'.join(ans) if ans else 'ready')