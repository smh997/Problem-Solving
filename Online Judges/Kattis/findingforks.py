"""
Author https://github.com/smh997/
https://open.kattis.com/problems/findingforks
"""

n = int(input())
li = sorted(list(map(int, input().split())))
print(li[0] + li[1])
