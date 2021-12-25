"""
https://open.kattis.com/problems/reachableroads
Author: https://github.com/smh997/
"""
numcities = int(input())
for i in range(numcities):
    cities = int(input())
    r = int(input())
    unvisited = set(range(int(cities)))
    connections = {x: [] for x in unvisited}
    for j in range(r):
        a, b = map(int, input().split())
        connections[a].append(b)
        connections[b].append(a)
    adds = -1
    while unvisited:
        adds += 1
        to_check = [unvisited.pop()]
        while to_check:
            hub = to_check.pop()
            for endpoint in connections[hub]:
                if endpoint in unvisited:
                    unvisited.remove(endpoint)
                    to_check.append(endpoint)
    print(adds)
