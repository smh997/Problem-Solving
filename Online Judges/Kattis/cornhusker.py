"""
Author https://github.com/smh997/
https://open.kattis.com/problems/cornhusker
"""

li = list(map(int, input().split()))
a, b = map(int, input().split())
print((int)(a * (sum([li[i] * li[i+1] for i in range(0, 10, 2)]) // 5) // b))
