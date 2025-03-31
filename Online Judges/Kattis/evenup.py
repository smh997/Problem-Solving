"""
https://open.kattis.com/problems/evenup
Author: https://github.com/smh997/
"""

n = int(input())
inp = list(map(int, input().split()))
st = [inp[0]]
for i in range(n-1):
    val = inp[i+1]
    if not len(st) or (st[-1] + val) % 2:
        st.append(val)
    else:
        st.pop()
print(len(st))