"""
https://open.kattis.com/problems/odds
Author: https://github.com/smh997/
"""
from math import gcd

mp = {'21': 1, '12': 1, '66': 2, '55': 3, '44': 4, '33': 5, '22': 6, '11': 7}


def check(a, b, c, d):
    global mp
    a, b, c, d = int(a), int(b), int(c), int(d)
    return mp[str(max(a, b)) + str(min(a, b))] < mp[str(max(c, d)) + str(min(c, d))]


cnt = 8
for i in reversed(range(3, 7)):
    for j in reversed(range(1, i)):
        mp[str(i)+str(j)] = cnt
        cnt += 1

while True:
    s0, s1, r0, r1 = map(str, input().split())
    li = [s0, s1, r0, r1]
    if (s0, s1, r0, r1) == ('0', '0', '0', '0'):
        break
    res = 0
    if li.count('*') == 0:
        print(1 if check(s0, s1, r0, r1) else 0)
    elif li.count('*') == 1:
        if s0 == '*':
            for i in range(1, 7):
                if check(i, s1, r0, r1):
                    res += 1
        elif s1 == '*':
            for i in range(1, 7):
                if check(s0, i, r0, r1):
                    res += 1
        elif r0 == '*':
            for i in range(1, 7):
                if check(s0, s1, i, r1):
                    res += 1
        else:
            for i in range(1, 7):
                if check(s0, s1, r0, i):
                    res += 1
        g = gcd(res, 6)
        ss = str(res//g) + '/' + str(6//g)
        print(1 if ss == '1/1' else 0 if ss == '0/1' else ss)
    elif li.count('*') == 2:
        if (s0, s1) == ('*', '*'):
            for i in range(1, 7):
                for j in range(1, 7):
                    if check(i, j, r0, r1):
                        res += 1
        elif (s0, r0) == ('*', '*'):
            for i in range(1, 7):
                for j in range(1, 7):
                    if check(i, s1, j, r1):
                        res += 1
        elif (s0, r1) == ('*', '*'):
            for i in range(1, 7):
                for j in range(1, 7):
                    if check(i, s1, r0, j):
                        res += 1
        elif (s1, r0) == ('*', '*'):
            for i in range(1, 7):
                for j in range(1, 7):
                    if check(s0, i, j, r1):
                        res += 1
        elif (s1, r1) == ('*', '*'):
            for i in range(1, 7):
                for j in range(1, 7):
                    if check(s0, i, r0, j):
                        res += 1
        elif (r0, r1) == ('*', '*'):
            for i in range(1, 7):
                for j in range(1, 7):
                    if check(s0, s1, i, j):
                        res += 1
        g = gcd(res, 36)
        ss = str(res // g) + '/' + str(36 // g)
        print(1 if ss == '1/1' else 0 if ss == '0/1' else ss)
    elif li.count('*') == 3:
        if s0 != '*':
            for i in range(1, 7):
                for j in range(1, 7):
                    for k in range(1, 7):
                        if check(s0, i, j, k):
                            res += 1
        elif s1 != '*':
            for i in range(1, 7):
                for j in range(1, 7):
                    for k in range(1, 7):
                        if check(i, s1, j, k):
                            res += 1
        elif r0 != '*':
            for i in range(1, 7):
                for j in range(1, 7):
                    for k in range(1, 7):
                        if check(i, j, r0, k):
                            res += 1
        else:
            for i in range(1, 7):
                for j in range(1, 7):
                    for k in range(1, 7):
                        if check(i, j, k, r1):
                            res += 1
        g = gcd(res, 216)
        ss = str(res // g) + '/' + str(216 // g)
        print(1 if ss == '1/1' else 0 if ss == '0/1' else ss)
    elif li.count('*') == 4:
        print('205/432')
