"""
https://open.kattis.com/problems/uniquedice
Author: https://github.com/smh997/
"""
n = int(input())
li = {}
for i in range(n):
    a, b, c, d, e, f = map(int, input().split())
    if (b, a, c, d, f, e) in li:
        li[(b, a, c, d, f, e)] += 1
    elif (b, a, e, f, c, d) in li:
        li[(b, a, e, f, c, d)] += 1
    elif (b, a, d, c, e, f) in li:
        li[(b, a, d, c, e, f)] += 1
    elif (b, a, f, e, d, c) in li:
        li[(b, a, f, e, d, c)] += 1
    elif (a, b, c, d, e, f) in li:
        li[(a, b, c, d, e, f)] += 1
    elif (a, b, f, e, c, d) in li:
        li[(a, b, f, e, c, d)] += 1
    elif (a, b, d, c, f, e) in li:
        li[(a, b, d, c, f, e)] += 1
    elif (a, b, e, f, d, c) in li:
        li[(a, b, e, f, d, c)] += 1
    elif (c, d, a, b, f, e) in li:
        li[(c, d, a, b, f, e)] += 1
    elif (c, d, e, f, a, b) in li:
        li[(c, d, e, f, a, b)] += 1
    elif (c, d, b, a, e, f) in li:
        li[(c, d, b, a, e, f)] += 1
    elif (c, d, f, e, b, a) in li:
        li[(c, d, f, e, b, a)] += 1
    elif (d, c, a, b, e, f) in li:
        li[(d, c, a, b, e, f)] += 1
    elif (d, c, f, e, a, b) in li:
        li[(d, c, f, e, a, b)] += 1
    elif (d, c, b, a, f, e) in li:
        li[(d, c, b, a, f, e)] += 1
    elif (d, c, e, f, b, a) in li:
        li[(d, c, e, f, b, a)] += 1
    elif (e, f, c, d, b, a) in li:
        li[(e, f, c, d, b, a)] += 1
    elif (e, f, a, b, c, d) in li:
        li[(e, f, a, b, c, d)] += 1
    elif (e, f, d, c, a, b) in li:
        li[(e, f, d, c, a, b)] += 1
    elif (e, f, b, a, d, c) in li:
        li[(e, f, b, a, d, c)] += 1
    elif (f, e, a, b, d, c) in li:
        li[(f, e, a, b, d, c)] += 1
    elif (f, e, c, d, a, b) in li:
        li[(f, e, c, d, a, b)] += 1
    elif (f, e, d, c, b, a) in li:
        li[(f, e, d, c, b, a)] += 1
    elif (f, e, b, a, c, d) in li:
        li[(f, e, b, a, c, d)] += 1
    else:
        li[(b, a, c, d, f, e)] = 1
print(max(li.values()))
