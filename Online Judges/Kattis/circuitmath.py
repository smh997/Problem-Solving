"""
https://open.kattis.com/problems/circuitmath
Author: https://github.com/smh997/
"""
n = int(input())
values = input().split()
v = [False]*n
for i in range(n):
    v[i] = True if values[i] == 'T' else False
s = input().split()
st = []
for i in range(len(s)):
    if s[i] not in ['*', '+', '-']:
        st.append(v[ord(s[i])-ord('A')])
    elif s[i] == '*':
        b1 = st[len(st)-1]
        st.pop()
        b2 = st[len(st) - 1]
        st.pop()
        st.append(b1 and b2)
    elif s[i] == '+':
        b1 = st[len(st) - 1]
        st.pop()
        b2 = st[len(st) - 1]
        st.pop()
        st.append(b1 or b2)
    else:
        b1 = st[len(st) - 1]
        st.pop()
        st.append(not b1)
print('T' if st[0] else 'F')
