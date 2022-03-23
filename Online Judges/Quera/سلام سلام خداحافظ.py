"""
https://quera.org/problemset/31021/
Author: https://github.com/smh997/
"""
n = int(input())
li = input().split()
for i in range(1, n):
    for j in reversed(range(0, i)):
        print(li[i] + ": salam " + li[j] + "!")
for i in range(n):
    print(li[i] + ": khodafez bacheha!")
    for j in range(i + 1, n):
        print(li[j] + ": khodafez " + li[i] + "!")
