"""
https://quera.org/problemset/34083/
Author: https://github.com/smh997/
"""
n = int(input())
d = dict()
money = dict()
for i in range(n):
    li = list(map(str, input().split()))
    if int(li[0]) == 1:
        ip, username = li[1].split(':')
        if '*' in username or '$' in username or '_' in username or '#' in username:
            print('invalid username')
        else:
            d[username] = ip
            money[ip] = 0
    elif int(li[0]) == 2:
        sender, receiver, mon = li[1].split(':')
        money[sender] -= int(mon)
        money[d[receiver]] += int(mon)
    else:
        print(money[li[1]])
