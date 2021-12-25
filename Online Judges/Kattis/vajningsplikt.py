"""
https://open.kattis.com/problems/vajningsplikt
Author: https://github.com/smh997/
"""
mp = {'North': 0, 'West': 1, 'South': 2, 'East': 3}
ari, go, oth = map(str, input().split())
print('Yes' if (mp[ari] % 2 == mp[go] % 2 and mp[oth] == (mp[ari]+1) % 4) or ((mp[ari]+3) % 4 == mp[go] and (mp[oth] == (mp[ari]+1) % 4 or mp[ari] % 2 == mp[oth] % 2)) else 'No')