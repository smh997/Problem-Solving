"""
https://open.kattis.com/problems/fairdivision
Author: https://github.com/smh997/
"""
t = int(input())
for i in range(t):
    p, n = map(int, input().split())
    limits = list(map(int, input().split()))
    res = [0] * n
    li = [[0, j] for j in range(n)]
    flag = False
    while p:
        # print(li, p)
        if len(li) == 0:
            flag = True
            break
        fair = p // len(li)
        if fair == 0:
            break
        candid = []
        for j in range(len(li)):
            if limits[li[j][1]] >= li[j][0] + fair:
                li[j][0] += fair
                p -= fair
                res[li[j][1]] += fair
                if li[j][0] == limits[li[j][1]]:
                    candid.append(j)
            else:
                res[li[j][1]] += limits[li[j][1]] - li[j][0]
                p -= limits[li[j][1]] - li[j][0]
                candid.append(j)
        candid.sort(reverse=True)
        for a in candid:
            # print(a, li)
            li.pop(a)
    if not flag and p:
        it = 0
        li2 = []
        for a in li:
            li2.append((-limits[a[1]], a[1]))
        li2.sort()
        while p:
            res[li2[it][1]] += 1
            p -= 1
            it += 1
    if flag:
        print('IMPOSSIBLE')
    else:
        print(' '.join([str(aa) for aa in res]))
