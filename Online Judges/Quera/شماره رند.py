"""
https://quera.org/problemset/91713/
Author: https://github.com/smh997/
"""
def c4(n):
    for ch in n:
        if n.count(ch) >= 4:
            return True
    return False


def c3(n):
    for j in range(6):
        if n[j:j + 3] == 3 * n[j]:
            return True
    return False


t = int(input())
for i in range(t):
    number = input()
    if c4(number) or c3(number) or number == number[::-1]:
        print('Ronde!')
    else:
        print('Rond Nist')
