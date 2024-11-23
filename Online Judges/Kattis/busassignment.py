n = int(input())
ans, cap = 0, 0
for _ in range(n):
    a, b = map(int, input().split())
    cap = cap - a + b
    ans = max(cap, ans)
print(ans)