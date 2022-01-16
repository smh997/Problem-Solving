"""
https://open.kattis.com/problems/keytocrypto
Author: https://github.com/smh997/
"""
cipher = input()
k = input()
le = len(cipher)
orig = ''
for i in range(le):
    ch = chr(ord('A') + ((ord(cipher[i]) - ord('A')) - (ord(k[i]) - ord('A')) + 26) % 26)
    orig += ch
    k += ch
print(orig)