"""
https://open.kattis.com/problems/ptice
Author: https://github.com/smh997/
"""
n = int(input())
s = input()
li = ['ABC', 'BABC', 'CCAABB']
su = [0] * 3
for i in range(n):
    for j in range(3):
        if s[i] == li[j][i % len(li[j])]:
            su[j] += 1
m = max(su)
print(m)
for i in range(3):
    if su[i] == m:
        print('Adrian' if not i else 'Bruno' if i == 1 else 'Goran')
