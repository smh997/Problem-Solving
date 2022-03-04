"""
https://quera.org/problemset/6375/
Author: https://github.com/smh997/
"""
li = list(map(int, input().split()))
mid = sum(li) / 3
li.sort()
if li[0] == mid:
    print(0)
elif li[1] == mid:
    print(1)
else:
    print(2)
