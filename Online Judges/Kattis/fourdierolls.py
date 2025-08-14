"""
Author https://github.com/smh997/
https://open.kattis.com/problems/fourdierolls
"""
def fact(a):
    if a == 1:
        return a
    return a * fact(a-1)

n = int(input())
li = list(map(int, input().split()))
if n > 1:
    for a in li:
        if li.count(a) > 1:
            print(0, 6**(4-n))
            exit(0)
a = fact(6-n) // 2
print(a, 6 ** (4-n) - a)
