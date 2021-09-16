"""
https://open.kattis.com/problems/busnumbers
Author: https://github.com/smh997/
"""
n = int(input())
li = list(map(int, input().split()))
li.sort()
s = 0
if len(li) == 1:
    print(li[0])
else:
    for i in range(1, len(li)):
        if li[i] != li[i-1] + 1:
            if i-1 - s == 0:
                print(li[s], end=' ')
            elif i-1 - s == 1:
                print(li[s], li[i-1], end=' ')
            else:
                print("{}-{}".format(li[s], li[i-1]), end=' ')
            s = i
if len(li)-1 - s == 0:
    print(li[s], end=' ')
elif len(li)-1 - s == 1:
    print(li[s], li[len(li)-1], end=' ')
else:
    print("{}-{}".format(li[s], li[len(li)-1]), end=' ')
