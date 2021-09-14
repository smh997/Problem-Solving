"""
https://open.kattis.com/problems/addingwords
Author: https://github.com/smh997/
"""
import sys
df = {}
ind = {}
for line in sys.stdin:
    li = line.split()
    if li[0] == 'calc':
        f = False
        tmp = 0
        for i in range(1, len(li) - 1):
            if i % 2 == 1 and li[i] not in df:
                f = True
                break
            if i == 1:
                tmp = df[li[i]]
            elif li[i - 1] == '+':
                tmp += df[li[i]]
            elif li[i - 1] == '-':
                tmp -= df[li[i]]
        for i in range(1, len(li)):
            print(li[i], end=' ')
        if f or tmp not in ind:
            print('unknown')
        else:
            print(ind[tmp])
    elif li[0] == 'def':
        if li[1] in df:
            del ind[df[li[1]]]
        df[li[1]] = int(li[2])
        ind[int(li[2])] = li[1]
    elif li[0] == 'clear':
        df.clear()
        ind.clear()

