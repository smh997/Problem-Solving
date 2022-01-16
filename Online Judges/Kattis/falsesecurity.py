"""
https://open.kattis.com/problems/falsesecurity
Author: https://github.com/smh997/
"""
import sys
dc = {'.-': 'A', '-...': 'B', '-.-.': 'C', '-..': 'D', '.': 'E', '..-.': 'F', '--.': 'G', '....': 'H', '..': 'I', '.---': 'J', '-.-': 'K', '.-..': 'L', '--': 'M', '-.': 'N', '---': 'O', '.--.': 'P', '--.-': 'Q', '.-.': 'R', '...': 'S', '-': 'T', '..-': 'U', '...-': 'V', '.--': 'W', '-..-': 'X', '-.--': 'Y', '--..': 'Z', '..--': '_', '.-.-': ',', '---.': '.', '----': '?'}
ec = {'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.', 'G': '--.', 'H': '....', 'I': '..', 'J': '.---', 'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---', 'P': '.--.', 'Q': '--.-', 'R': '.-.', 'S': '...', 'T': '-', 'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-', 'Y': '-.--', 'Z': '--..', '_': '..--', ',': '.-.-', '.': '---.', '?': '----'}
li = []
inp = ''
lines = sys.stdin.readlines()
for line in lines:
    li.clear()
    inp = ''
    for ch in line.strip():
        li.append(len(ec[ch]))
        inp += ec[ch]
    li.reverse()
    s = 0
    for i in range(len(li)):
        print(dc[inp[s:s+li[i]]], end='')
        s += li[i]
    print()