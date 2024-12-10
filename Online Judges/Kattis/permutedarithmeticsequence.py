"""
https://open.kattis.com/problems/permutedarithmeticsequence
Author: https://github.com/smh997/
"""

def check(lis, dif):
    return False not in [lis[i] - i * dif == lis[0] for i in range(1, len(lis))]

n = int(input())
for _ in range(n):
    li = list(map(int, input().split()))[1:]
    ans = check(li, li[1]-li[0])
    li.sort()
    print('arithmetic' if ans else 'permuted arithmetic' if check(li, li[1]-li[0]) else 'non-arithmetic')
