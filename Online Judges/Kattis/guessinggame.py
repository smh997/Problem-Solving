"""
https://open.kattis.com/problems/guessinggame
Author: https://github.com/smh997/
"""
a, b = 1, 10
fl = False
while True:
    n = int(input())
    if not n:
        break
    s = input()
    if s == 'right on':
        print('Stan is dishonest' if fl or n < a or n > b else 'Stan may be honest')
        a, b = 1, 10
        fl = False
        continue
    if fl:
        continue
    if (n >= b and s == 'too low') or (n <= a and s == 'too high') or a > b:
        fl = True
    if s == 'too low':
        a = max(n + 1, a)
    elif s == 'too high':
        b = min(n - 1, b)
