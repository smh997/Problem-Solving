"""
https://open.kattis.com/problems/provincesandgold
Author: https://github.com/smh997/
"""
v = [(8, 'Province'), (5, 'Duchy'), (2, 'Estate')]
t = [(6, 3, 'Gold'), (3, 2, 'Silver '), (0, 1, 'Copper')]
g, s, c = map(int, input().split())
m = g * t[0][1] + s * t[1][1] + c * t[2][1]
bv, bt = '', ''
for i in range(3):
    if m >= v[i][0]:
        bv = v[i][1]
        break
for i in range(3):
    if m >= t[i][0]:
        bt = t[i][2]
        break
print(bv+' or '+bt if bv != '' else bt)
