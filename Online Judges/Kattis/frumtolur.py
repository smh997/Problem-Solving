"""
https://open.kattis.com/problems/frumtolur
Author: https://github.com/smh997/
"""

def isPrime(a):
    for i in range(2, a // 2 + 1):
        if a % i == 0:
            return False
    return True

ans = [2]
a = 3
while len(ans) < 100:
    if isPrime(a):
        ans.append(a)
    a += 2
print('\n'.join(list(map(str, ans))))