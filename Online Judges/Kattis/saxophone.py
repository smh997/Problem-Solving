"""
https://open.kattis.com/problems/saxophone
Author: https://github.com/smh997/
"""
di = {'c': [2, 3, 4, 7, 8, 9, 10], 'd': [2, 3, 4, 7, 8, 9], 'e': [2, 3, 4, 7, 8], 'f': [2, 3, 4, 7], 'g': [2, 3, 4], 'a': [2, 3], 'b': [2], 'C': [3], 'D': [1, 2, 3, 4, 7, 8, 9], 'E': [1, 2, 3, 4, 7, 8], 'F': [1, 2, 3, 4, 7], 'G': [1, 2, 3, 4], 'A': [1, 2, 3], 'B': [1, 2]}
n = int(input())
for _ in range(n):
    s = input()
    inpress = [False for i in range(11)]
    cntpress = [0 for i in range(11)]
    for a in s:
        for k in range(1, 11):
            if k in di[a]:
                if not inpress[k]:
                    cntpress[k] += 1
                    inpress[k] = True
            else:
                inpress[k] = False
    print(' '.join([str(aa) for aa in cntpress[1:]]))
