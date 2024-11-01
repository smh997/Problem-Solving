"""
https://open.kattis.com/problems/takkfyrirmig
Author: https://github.com/smh997/
"""
n = int(input())
li = [input() for _ in range(n)]
print('\n'.join([f'Takk {a}' for a in li]))