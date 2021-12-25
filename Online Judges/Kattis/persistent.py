"""
https://open.kattis.com/problems/persistent
Author: https://github.com/smh997/
"""
while True:
    n = int(input())
    if n == -1:
        break
    if n < 10:
        print('1' + str(n))
        continue
    res = []
    flag = False
    while n != 1:
        flag = False
        for i in reversed(range(2, 10)):
            if n % i == 0:
                n //= i
                res.append(str(i))
                flag = True
                break
        if not flag:
            print('There is no such number.')
            break
    if not flag:
        continue
    res.reverse()
    print(''.join(res))
