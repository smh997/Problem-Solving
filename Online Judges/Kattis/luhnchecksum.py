"""
https://open.kattis.com/problems/luhnchecksum
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    s = 0
    inp = input()[::-1]
    for j in range(len(inp)):
        li = list(map(int, inp))
        s += li[j] if not j % 2 else li[j] * 2 if li[j] * 2 < 10 else sum(list(map(int, (str(li[j]*2)))))
    print('PASS' if not s % 10 else 'FAIL')

