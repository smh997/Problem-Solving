"""
https://open.kattis.com/problems/electionparadox
Author: https://github.com/smh997/
"""

n = int(input())
li = sorted(list(map(int, input().split())), reverse = True)
print(sum(li[:len(li) // 2]) + sum([a // 2 for a in li[len(li) // 2:]]))
