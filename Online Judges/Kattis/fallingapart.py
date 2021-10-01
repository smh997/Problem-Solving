"""
https://open.kattis.com/problems/fallingapart
Author: https://github.com/smh997/
"""
n = int(input())
li = list(map(int, input().split()))
li.sort(reverse=True)
print(sum([li[i] for i in range(len(li)) if not (i % 2)]), sum([li[i] for i in range(len(li)) if i % 2]))