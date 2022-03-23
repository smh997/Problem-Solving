"""
https://quera.org/problemset/102256/
Author: https://github.com/smh997/
"""
n = int(input())
li = map(int, input().split())
k = int(input())
mod = 1000000007
ml = []
mp = {}
for amount in li:
    if amount not in mp:
        ml.append(amount)
        mp[amount] = 0
    mp[amount] += 1
ml.sort(reverse=True)
res = 0
for i, amount in enumerate(ml):
    nxt_am = ml[i + 1] if i < len(ml) - 1 else 0
    if nxt_am != amount - 1:
        tedad = mp[amount]
        rng = (amount - nxt_am) * tedad
        if k > rng:
            res = (res + (((amount * (amount + 1) // 2) - (nxt_am * (nxt_am + 1) // 2)) * tedad) % mod) % mod
            k -= rng
            mp[nxt_am] += tedad
        else:
            myrng = k // tedad
            rem = k % tedad
            nxt_am = amount - myrng
            res = (res + (((amount * (amount + 1) // 2) - (nxt_am * (nxt_am + 1) // 2)) * tedad) % mod) % mod
            res = (res + (nxt_am * rem) % mod) % mod
            k = 0
            break
    else:
        tedad = mp[amount]
        if k >= tedad:
            res = (res + (tedad * amount) % mod) % mod
            k -= tedad
            mp[amount - 1] += tedad
        else:
            res = (res + (k * amount) % mod) % mod
            k = 0
            break
print(int(res))
