"""
https://open.kattis.com/problems/asciiaddition
Author: https://github.com/smh997/
"""
mp = {('xxxxx', 'x...x', 'x...x', 'x...x', 'x...x', 'x...x', 'xxxxx'): '0', ('....x', '....x', '....x', '....x', '....x', '....x', '....x'): '1',
      ('xxxxx', '....x', '....x', 'xxxxx', 'x....', 'x....', 'xxxxx'): '2', ('xxxxx', '....x', '....x', 'xxxxx', '....x', '....x', 'xxxxx'): '3',
      ('x...x', 'x...x', 'x...x', 'xxxxx', '....x', '....x', '....x'): '4', ('xxxxx', 'x....', 'x....', 'xxxxx', '....x', '....x', 'xxxxx'): '5',
      ('xxxxx', 'x....', 'x....', 'xxxxx', 'x...x', 'x...x', 'xxxxx'): '6', ('xxxxx', '....x', '....x', '....x', '....x', '....x', '....x'): '7',
      ('xxxxx', 'x...x', 'x...x', 'xxxxx', 'x...x', 'x...x', 'xxxxx'): '8', ('xxxxx', 'x...x', 'x...x', 'xxxxx', '....x', '....x', 'xxxxx'): '9',
      ('.....', '..x..', '..x..', 'xxxxx', '..x..', '..x..', '.....'): '+'}
lines = []
li = [('xxxxx', 'x...x', 'x...x', 'x...x', 'x...x', 'x...x', 'xxxxx'), ('....x', '....x', '....x', '....x', '....x', '....x', '....x'),
      ('xxxxx', '....x', '....x', 'xxxxx', 'x....', 'x....', 'xxxxx'), ('xxxxx', '....x', '....x', 'xxxxx', '....x', '....x', 'xxxxx'),
      ('x...x', 'x...x', 'x...x', 'xxxxx', '....x', '....x', '....x'), ('xxxxx', 'x....', 'x....', 'xxxxx', '....x', '....x', 'xxxxx'),
      ('xxxxx', 'x....', 'x....', 'xxxxx', 'x...x', 'x...x', 'xxxxx'), ('xxxxx', '....x', '....x', '....x', '....x', '....x', '....x'),
      ('xxxxx', 'x...x', 'x...x', 'xxxxx', 'x...x', 'x...x', 'xxxxx'), ('xxxxx', 'x...x', 'x...x', 'xxxxx', '....x', '....x', 'xxxxx')]

def build(idx):
    global mp, lines
    tu = (lines[0][idx:idx+5], lines[1][idx:idx+5], lines[2][idx:idx+5], lines[3][idx:idx+5], lines[4][idx:idx+5], lines[5][idx:idx+5], lines[6][idx:idx+5])
    return mp[tu]

for i in range(7):
    lines.append(input())
le = len(lines[0])
flag = True
a = ''
b = ''
for i in range(0, le, 6):
    dig = build(i)
    if dig == '+':
        flag = False
    elif flag:
        a += dig
    else:
        b += dig
res = str(int(a) + int(b))
reslis = []
for i in range(len(res)):
    reslis.append(li[int(res[i])])
for i in range(7):
    for j in range(len(res)):
        if not j:
            print(reslis[j][i], end='')
        else:
            print('.' + reslis[j][i], end='')
    print()
