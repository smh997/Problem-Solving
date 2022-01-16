"""
https://open.kattis.com/problems/tripletexting
Author: https://github.com/smh997/
"""
s = input()
a, b, c = s[:len(s) // 3], s[len(s) // 3:len(s) * 2 // 3], s[len(s) * 2 // 3:]
print(a if a == b or a == c else b)