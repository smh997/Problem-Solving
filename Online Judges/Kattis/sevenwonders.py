"""
https://open.kattis.com/problems/sevenwonders
Author: https://github.com/smh997/
"""
inp = input()
t, c, g = inp.count('T'), inp.count('C'), inp.count('G')
print(t ** 2 + c ** 2 + g ** 2 + 7 * min(t, c, g))