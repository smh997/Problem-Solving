li = list(map(int, input().split())) + [0]
ans = ['A', 'B', 'C', 'D', 'E', 'F']
g = int(input())
for i in range(6):
    if g >= li[i]:
        print(ans[i])
        break