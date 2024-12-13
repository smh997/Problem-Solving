n, t = map(int, input().split())
tsk = list(map(int, input().split()))
for i in range(n):
    if t - tsk[i] < 0:
        print(i)
        exit(0)
    t -= tsk[i]
print(n)