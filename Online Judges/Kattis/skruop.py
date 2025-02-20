n = int(input())
ans = 7
for _ in range(n):
    if input() == "Skru op!":
        ans = min(10, ans + 1)
    else:
        ans = max(0, ans - 1)
print(ans)