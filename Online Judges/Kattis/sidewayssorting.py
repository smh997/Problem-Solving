"""
https://open.kattis.com/problems/sidewayssorting
Author: https://github.com/smh997/
"""
from operator import itemgetter

while True:
    r, c = map(int, input().split())
    if not (r and c):
        break
    words = [''] * c
    for i in range(r):
        for j, ch in enumerate(input()):
            words[j] = words[j] + ch
    words = [(word, word.lower()) for word in words]
    words.sort(key=itemgetter(1))
    for i in range(r):
        for j in range(c):
            print(words[j][0][i], end='')
        print()
    print()
