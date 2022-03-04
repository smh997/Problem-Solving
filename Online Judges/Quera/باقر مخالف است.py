"""
https://quera.org/problemset/10233/
Author: https://github.com/smh997/
"""
x = int(input())
arr = [0 for i in range(10)]
arr[x % 10] += 1
y = x // 10
target = -1
for i in range(len(str(x)) - 1):
    for j in range(y % 10 + 1, 10):
        if arr[j] > 0:
            arr[j] -= 1
            target = j
            break
    arr[y % 10] += 1
    y = y // 10
    if target != -1:
        break
if y != 0:
    print(y, end="")
if target != -1:
    print(target, end="")
    for k in range(10):
        for l in range(arr[k]):
            print(k, end="")
else:
    print(0)
