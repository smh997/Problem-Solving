"""
https://open.kattis.com/problems/piglatin
Author: https://github.com/smh997/
"""
import sys
lines = sys.stdin.readlines()
for line in lines:
    li = line.split()
    for w in range(len(li)):
        if li[w][0] in ['a', 'e', 'o', 'i', 'u', 'y']:
            print(li[w]+'yay', end='')
        else:
            for c in range(len(li[w])):
                if li[w][c] in ['a', 'e', 'o', 'i', 'u', 'y']:
                    print(li[w][c:]+li[w][:c]+'ay', end='')
                    break
        if w != len(li) - 1:
            print(' ', end='')
        else:
            print()

