"""
https://open.kattis.com/problems/bitsequalizer
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    s = input()
    t = input()
    s1, t1 = s.count('1'), t.count('1')
    if s1 > t1:
        print('Case %d: %d' % (i+1, -1))
        continue
    sli = [a for a in s]
    tli = [a for a in t]
    res = 0
    ss = 0
    if s1 == t1:
        for j in range(len(s)):
            if sli[j] == '?':
                sli[j] = '0'
                res += 1
        for j in range(len(s)):
            if sli[j] != tli[j]:
                ss += 1
        print('Case %d: %d' % (i+1, res + ss // 2))
    else:
        cnt = t1 - s1
        for j in range(len(s)):
            if sli[j] == '?':
                if tli[j] == '1' and cnt > 0:
                    sli[j] = '1'
                    cnt -= 1
                else:
                    sli[j] = '0'
                res += 1
        for j in range(len(s)):
            if sli[j] != tli[j]:
                if tli[j] == '1' and cnt > 0:
                    sli[j] = '1'
                    cnt -= 1
                    res += 1
                else:
                    ss += 1
        print('Case %d: %d' % (i+1, res + ss // 2))
