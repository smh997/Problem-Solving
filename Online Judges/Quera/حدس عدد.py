"""
https://quera.org/problemset/2596/
Author: https://github.com/smh997/
"""
def gcd(a, b):
    if b == 0:
        return a
    c = a % b
    a = b
    b = c
    return gcd(a, b)


def lcd(a, b):
    if a < b:
        a, b = b, a
    return a * b // gcd(a, b)


if __name__ == "__main__":
    n = int(input())
    li = list(map(int, input().split()))
    li.sort()
    m = 1
    for a in li:
        m = lcd(a, m)
    print(1000 // m)

