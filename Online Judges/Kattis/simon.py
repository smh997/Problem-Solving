"""
https://open.kattis.com/problems/simon
Author: https://github.com/smh997/
"""
t = int(input())
for i in range(t):
    inp = input()
    if inp.startswith('simon says'):
        print(inp[11:])
    else:
        print()