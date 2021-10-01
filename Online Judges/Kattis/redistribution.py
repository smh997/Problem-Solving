"""
https://open.kattis.com/problems/redistribution
Author: https://github.com/smh997/
"""
n = int(input())
li = list(map(int, input().split()))
li2 = sorted([(li[i], i+1) for i in range(n)])
if li2[n-1][0] > sum(li) - li2[n-1][0]:
    print('impossible')
else:
    for i in reversed(range(n)):
        print(li2[i][1], end=' ')
    print()
