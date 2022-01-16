"""
https://open.kattis.com/problems/tritiling
Author: https://github.com/smh997/
"""
dp = [0] * 31
dp[0] = 1
dp[2] = 3
for i in range(4, 31):
    dp[i] = dp[i-2]*4 - dp[i-4]
while True:
    inp = int(input())
    if inp == -1:
        break
    print(dp[inp])
