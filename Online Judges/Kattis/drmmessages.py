"""
https://open.kattis.com/problems/drmmessages
Author: https://github.com/smh997/
"""
inp = input()
inp1 = inp[:len(inp)//2]
r1 = sum([ord(ch) - ord('A') for ch in inp1])
inp2 = inp[len(inp)//2:]
r2 = sum([ord(ch) - ord('A') for ch in inp2])
inp1 = [chr((ord(ch)+r1) % 26 + ord('A')) for ch in inp1]
inp2 = [chr((ord(ch)+r2) % 26 + ord('A')) for ch in inp2]
for i in range(len(inp1)):
    print(chr(((ord(inp1[i])-ord('A')) + (ord(inp2[i]) - ord('A'))) % 26 + ord('A')), end='')
print()