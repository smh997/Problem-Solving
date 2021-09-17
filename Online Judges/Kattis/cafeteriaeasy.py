"""
https://open.kattis.com/problems/cafeteriaeasy
Author: https://github.com/smh997/
"""
from fractions import Fraction
# a, b = map(int, input().split())
# f = Fraction(a, b)
# proportion = {'01': '-', '10': '-', '02': '-', '20': '-', '03': '-', '30': '-', '12': '-', '21': '-', '31': '-', '13': '-', '23': '-', '32': '-'}
monster = []
inp1 = input().split()
inp2 = input().split()
for i in range(5):
    monster.append([inp1[2*i], inp1[2*i+1], inp2[2*i], inp2[2*i+1]])
while '_' in inp1 or '_' in inp2:
    for i in range(5):
        for a in range(4):
            for b in range(4):
                if a == b:
                    continue
                if monster[i][a] != '_' and monster[i][b] != '_':
                    f = Fraction(int(monster[i][a]), int(monster[i][b]))
                    for j in range(5):
                        if i == j:
                            continue
                        if monster[j][a] == '_' and monster[j][b] != '_':
                            monster[j][a] = str(int(monster[j][b]) * f.numerator // f.denominator)
                            if a < 2:
                                inp1[2 * j + a] = monster[j][a]
                            else:
                                inp2[2 * j + a % 2] = monster[j][a]
                            # print(i, j, a, b)
                        elif monster[j][a] != '_' and monster[j][b] == '_':
                            monster[j][b] = str(int(monster[j][a]) * f.denominator // f.numerator)
                            if b < 2:
                                inp1[2 * j + b] = monster[j][b]
                            else:
                                inp2[2 * j + b % 2] = monster[j][b]
                            # print(i, j, a, b)
print(' '.join(inp1))
print(' '.join(inp2))