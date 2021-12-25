"""
https://open.kattis.com/problems/pubnite
Author: https://github.com/smh997/
"""
x, y, s, ri, rf = map(float, input().split())
xa, ya, sa = map(float, input().split())
posa = ((x - xa)**2 + (y - ya)**2)**0.5
if posa <= rf:
    print(0)
else:
    if posa > ri:
        if sa <= s:
            print('%.7f' % ((posa-rf)/sa))
        else:
            if (posa - ri)/(sa - s) >= (posa-rf)/sa:
                print('%.7f' % ((posa-rf)/sa))
            else:
                print('%.7f' % ((posa - ri) / (sa - s)))
    else:
        if sa <= s:
            if s-sa == 0 or (ri - posa) / (s - sa) >= (posa - rf) / sa:
                print(0)
            else:
                print('%.7f' % ((posa - rf) / sa - (ri - posa) / (s - sa)))
        else:
            print(0)
