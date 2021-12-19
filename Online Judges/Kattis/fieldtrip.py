"""
https://open.kattis.com/problems/fieldtrip
Author: https://github.com/smh997/
"""
n = int(input())
li = list(map(int, input().split()))
s = sum(li)
if s % 3:
    print(-1)
    exit(0)
seg = s // 3
it1 = 0
res = 0
ans = []
for i in range(n):
    if res + li[i] == seg:
        ans.append(i+1)
        break
    if res + li[i] < seg:
        res += li[i]
    else:
        print(-1)
        exit(0)
res = 0
for i in range(ans[0], n):
    if res + li[i] == seg:
        ans.append(i+1)
        break
    if res + li[i] < seg:
        res += li[i]
    else:
        print(-1)
        exit(0)
print(ans[0], ans[1])