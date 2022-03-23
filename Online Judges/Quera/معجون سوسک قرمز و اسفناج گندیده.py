"""
https://quera.org/problemset/72880/
Author: https://github.com/smh997/
"""
a, b, c, d, m = map(int, input().split())
aa = a + m * c
bb = b + m * d
pa = aa - a
pb = bb - b
if (aa > bb and pa > pb) or (bb > aa and pb > pa):
    print('Eyval baba!')
else:
    print('Naaa, eshtebahe!')
