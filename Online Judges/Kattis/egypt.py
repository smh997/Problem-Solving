"""
https://open.kattis.com/problems/egypt
Author: https://github.com/smh997/
"""
li = list(map(int, input().split()))
while li[0] != 0 or li[1] != 0 or li[2] != 0:
    li.sort()
    if li[0]**2 + li[1]**2 == li[2]**2:
        print("right")
    else:
        print("wrong")
    li = list(map(int, input().split()))
