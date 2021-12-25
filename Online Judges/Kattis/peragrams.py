"""
https://open.kattis.com/problems/peragrams
Author: https://github.com/smh997/
"""
s = input()
li = []
for a in s:
    if a in li:
        li.remove(a)
    else:
        li.append(a)
print(len(li)-1 if len(li) else 0)