n = int(input())
a, ans = 0, ''
for i in range(n):
   bb, cc = map(str, input().split())
   if int(cc) >= a:
      ans = bb
      a = int(cc)
print(ans)
