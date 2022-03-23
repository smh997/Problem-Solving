"""
https://quera.org/problemset/3109/
Author: https://github.com/smh997/
"""
n = int(input())
li = []
while n != 1:
    li.append(n)
    if n % 2 == 0:
        n = n//2
    else:
        n = 3 * n + 3
    if n in li:
        print("No")
        break
if n == 1:
    print("Yes")
