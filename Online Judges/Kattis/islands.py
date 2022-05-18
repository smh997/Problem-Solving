"""
https://open.kattis.com/problems/islands
Author: https://github.com/smh997/
"""
p = int(input())
for c in range(p):
    ans = 0
    li = list(map(int, input().split()))[1:]
    for i in range(1, 11):
        for j in range(i, 11):
            flag = True
            for k in range(i, j + 1):
                if li[k] <= li[i - 1] or li[k] <= li[j + 1]:
                    flag = False
                    break
            if flag:
                ans += 1     

    print(c + 1, ans)