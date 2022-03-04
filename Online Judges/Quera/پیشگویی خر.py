"""
https://quera.org/problemset/4066/
Author: https://github.com/smh997/
"""
n, m = map(int, input().split())
li = {}
for i in range(n):
    inp = input().split()
    li[inp[0]] = inp[1]
s = input().split()
for a in s:
    if a in li.keys():
        print("%s " % li[a], end='')
    print("kachal! ", end='')
print()
