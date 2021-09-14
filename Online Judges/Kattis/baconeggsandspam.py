"""
https://open.kattis.com/problems/baconeggsandspam
Author: https://github.com/smh997/
"""
while True:
    n = int(input())
    if not n:
        break
    item_di = {}
    item_li = []
    for i in range(n):
        inp = input().split()
        for j in range(1, len(inp)):
            if inp[j] not in item_li:
                item_li.append(inp[j])
                item_di[inp[j]] = []
            item_di[inp[j]].append(inp[0])
    item_li.sort()
    for item in item_li:
        print(item, ' '.join(sorted(item_di[item])))
    print()
