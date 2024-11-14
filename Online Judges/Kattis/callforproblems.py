n = int(input())
ans = 0
for i in range(n):
    if int(input()) % 2:
        ans += 1
print(ans)