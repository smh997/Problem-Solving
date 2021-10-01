"""
https://open.kattis.com/problems/encodedmessage
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    s = input()
    for k in reversed(range(int(len(s)**0.5))):
        for j in range(int(len(s)**0.5)):
            print(s[j*int(len(s)**0.5)+k],end='')
    print()
