"""
https://open.kattis.com/problems/drunkvigenere
Author: https://github.com/smh997/
"""
e = input()
k = input()
d = ''
for i in range(len(e)):
    d += chr(ord('A')+(((ord(e[i])-ord('A'))+(ord(k[i])-ord('A')))+26) % 26) if i % 2 else chr(ord('A')+(((ord(e[i])-ord('A'))-(ord(k[i])-ord('A')))+26) % 26)
print(d)