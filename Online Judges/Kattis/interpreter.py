"""
https://open.kattis.com/problems/interpreter
Author: https://github.com/smh997/
"""

import sys

reg = [0 for i in range(10)]
ram = ['000' for j in range(1000)]
lines = sys.stdin.readlines()
for i in range(len(lines)):
    ram[i] = lines[i]
it, res = 0, 0
while True:
    res += 1
    if ram[it][0] == '0':
        if reg[int(ram[it][2])] != 0:
            it = reg[int(ram[it][1])]
            continue
    elif ram[it][0] == '1':
        break
    elif ram[it][0] == '2':
        reg[int(ram[it][1])] = int(ram[it][2])
    elif ram[it][0] == '3':
        reg[int(ram[it][1])] = (reg[int(ram[it][1])] + int(ram[it][2])) % 1000
    elif ram[it][0] == '4':
        reg[int(ram[it][1])] = (reg[int(ram[it][1])] * int(ram[it][2])) % 1000
    elif ram[it][0] == '5':
        reg[int(ram[it][1])] = reg[int(ram[it][2])]
    elif ram[it][0] == '6':
        reg[int(ram[it][1])] = (reg[int(ram[it][1])] + reg[int(ram[it][2])]) % 1000
    elif ram[it][0] == '7':
        reg[int(ram[it][1])] = (reg[int(ram[it][1])] * reg[int(ram[it][2])]) % 1000
    elif ram[it][0] == '8':
        reg[int(ram[it][1])] = int(ram[reg[int(ram[it][2])]])
    else:
        ram[reg[int(ram[it][2])]] = '{:0>3d}'.format(reg[int(ram[it][1])])
    it += 1
print(res)
