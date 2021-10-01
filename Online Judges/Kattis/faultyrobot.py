"""
https://open.kattis.com/problems/faultyrobot
Author: https://github.com/smh997/
"""
def trav(node, stat):
    global ans
    if vis[node] < stat:
        if not vis[node] and not force[node]:
            ans += 1
        vis[node] = stat
        if force[node]:
            trav(force[node], stat)
        if vis[node] == 2:
            for n in nei[node]:
                trav(n, 1)


n, m = map(int, input().split())
nei = [[] for i in range(n+1)]
force = [0] * (n+1)
vis = [0] * (n+1)
for i in range(m):
    a, b = map(int, input().split())
    if a < 0:
        force[-a] = b
    else:
        nei[a].append(b)
ans = 0
trav(1, 2)
print(ans)
