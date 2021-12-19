"""
https://open.kattis.com/problems/karte
Author: https://github.com/smh997/
"""
s = input()
mp = dict()
mp['P'], mp['K'], mp['H'], mp['T'] = [False] * 13, [False] * 13, [False] * 13, [False] * 13
for i in range(0, len(s), 3):
    if mp[s[i]][int(s[i+1: i+3])-1]:
        print('GRESKA')
        exit(0)
    else:
        mp[s[i]][int(s[i + 1: i + 3])-1] = True
for k in mp:
    print(len([mp[k][i] for i in range(13) if not mp[k][i]]), end=' ')
