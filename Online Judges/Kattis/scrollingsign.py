"""
https://open.kattis.com/problems/scrollingsign
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    k, w = map(int, input().split())
    pre = input()
    res = k
    for j in range(1, w):
        post = input()
        for o in reversed(range(k+1)):
            if pre.endswith(post[:o]):
                res += k - o
                break
        pre = post
    print(res)
