"""
https://open.kattis.com/problems/help2
Author: https://github.com/smh997/
"""
def calc(p1, p2):
    for i in range(len(p1)):
        if p1[i][0] == '<' and p1[i][-1] == '>' and not (p2[i][0] == '<' and p2[i][-1] == '>'):
            pl, w = p1[i], p2[i]
            for j in range(len(p1)):
                if p1[j] == pl:
                    p1[j] = w
            return calc(p1, p2)
        if p2[i][0] == '<' and p2[i][-1] == '>' and not (p1[i][0] == '<' and p1[i][-1] == '>'):
            pl, w = p2[i], p1[i]
            for j in range(len(p2)):
                if p2[j] == pl:
                    p2[j] = w
            return calc(p1, p2)
    for i in range(len(p1)):
        if p1[i][0] == '<' and p1[i][-1] == '>' and p2[i][0] == '<' and p2[i][-1] == '>':
            pl1, pl2 = p1[i], p2[i]
            for j in range(len(p1)):
                if p1[j] == pl1:
                    p1[j] = 'same'
            for j in range(len(p2)):
                if p2[j] == pl2:
                    p2[j] = 'same'
            return calc(p1, p2)
    if p1 == p2:
        print(' '.join(p1))
    else:
        print('-')


n = int(input())
while n:
    n -= 1
    p1 = list(map(str, input().split()))
    p2 = list(map(str, input().split()))
    if len(p1) != len(p2):
        print('-')
        continue
    calc(p1, p2)
