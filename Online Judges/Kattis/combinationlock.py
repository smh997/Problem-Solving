"""
https://open.kattis.com/problems/combinationlock
Author: https://github.com/smh997/
"""
while True:
    cur, a, b, c = map(int, input().split())
    if (cur, a, b, c) == (0, 0, 0, 0):
        break
    res = 1080
    res += ((cur-a if cur >= a else 40-(a-cur)) * 9)
    cur = a
    res += ((b-cur if b >= cur else 40-(cur-b)) * 9)
    cur = b
    res += ((cur-c if cur >= c else 40 - (c - cur)) * 9)
    print(res)
