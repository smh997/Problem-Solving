"""
https://open.kattis.com/problems/peasoup
Author: https://github.com/smh997/
"""
flag = False
n = int(input())
for i in range(n):
    k = int(input())
    name = input()
    li = []
    for item in range(k):
        li.append(input())
    if flag:
        continue
    if 'pea soup' in li and 'pancakes' in li:
        print(name)
        flag = True
if not flag:
    print('Anywhere is fine I guess')