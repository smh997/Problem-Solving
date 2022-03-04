"""
https://quera.org/problemset/3559/
Author: https://github.com/smh997/
"""
def abriz(i, side):
    global n, stock, cap
    if side == 'L':
        if i - 1 >= 0 and cap[i - 1] < stock[i]:
            stock[i - 1] = stock[i]
            if i - 1 == 0:
                return True
            if stock[i - 1] > cap[i - 1]:
                return abriz(i - 1, 'L')
    else:
        if i + 1 < n and cap[i + 1] < stock[i]:
            stock[i + 1] = stock[i]
            if i + 1 == n - 1:
                return True
            if stock[i + 1] > cap[i + 1]:
                return abriz(i + 1, 'R')
    return False

n, q = map(int, input().split())
stock = [0] * n
cap = list(map(int, input().split()))
ql = []
for i in range(q):
    ql.append(int(input()))
for i in range(q):
    k = ql[i] - 1
    stock[k] += 1
    if stock[k] > cap[k]:
        if abriz(k, 'L') or abriz(k, 'R'):
            print(i + 1)
            exit(0)
print('No Answer')
