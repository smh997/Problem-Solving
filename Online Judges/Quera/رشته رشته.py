"""
https://quera.org/problemset/108670/
Author: https://github.com/smh997/
"""
n, k = map(int, input().split())
li = [input() for i in range(n)]
reqs = [input() for j in range(k)]
print()
for i in range(k):
    sims = [False] * n
    a = reqs[i].lower()
    for j in range(n):
        if len(li[j]) != len(reqs[i]) and abs(len(li[j]) - len(reqs[i])) != 1:
            continue
        if li[j].lower() == a:
            sims[j] = True
            continue
        if abs(len(li[j]) - len(reqs[i])) == 1:
            for c in range(len(li[j])):
                b = li[j][:c] + li[j][c + 1:]
                if b == reqs[i]:
                    sims[j] = True
                    break
            if not sims[j]:
                for c in range(len(reqs[i])):
                    b = reqs[i][:c] + reqs[i][c + 1:]
                    if b == li[j]:
                        sims[j] = True
                        break
        if not sims[j] and len(li[j]) == len(reqs[i]):
            for c in range(len(li[j])):
                for replchar_i in range(ord('a'), ord('z')+1):
                    if li[j][:c] + chr(replchar_i) + li[j][c + 1:] == reqs[i]:
                        sims[j] = True
                        break
                if not sims[j]:
                    for replchar_i in range(ord('A'), ord('Z') + 1):
                        if li[j][:c] + chr(replchar_i) + li[j][c + 1:] == reqs[i]:
                            sims[j] = True
                            break
                if sims[j]:
                    break
    res = 0
    for m in range(n):
        if sims[m]:
            res += 1
    print(res)
