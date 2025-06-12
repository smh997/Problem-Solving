"""
Author https://github.com/smh997/
https://open.kattis.com/problems/searchwizard
"""
t = input()
n = int(input())
s = input()
ans = 0
for i in range(len(s) - len(t) + 1):
    if s[i: i+len(t)] == t:
        ans += 1
print(ans)
