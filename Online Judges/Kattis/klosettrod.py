"""
https://open.kattis.com/problems/klosettrod
Author: https://github.com/smh997/
"""

n = int(input())
li = list(map(int, input().split()))
print(' '.join([str(a[1]+1) for a in list(sorted([(li[i], i) for i in range(n)], reverse=True))]))