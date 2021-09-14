"""
https://open.kattis.com/problems/batmanacci
Author: https://github.com/smh997/
"""
fib = [0, 1, 1]
n, k = map(int, input().split())
for i in range(3, n+1):
    fib.append(fib[i-2] + fib[i-1])
while True:
    if n == 1:
        print('N')
        break
    elif n == 2:
        print('A')
        break
    if k > fib[n-2]:
        k -= fib[n-2]
        n = n - 1
    else:
        n = n - 2
