"""
https://open.kattis.com/problems/driversdilemma
Author: https://github.com/smh997/
"""
c, x, m = map(float, input().split())
mx = 0
c /= 2
for i in range(6):
    li = input().split()
    a, b = int(li[0]), float(li[1])
    time = m / a
    leak = time * x
    use = m / b
    if c - leak - use > 0:
        mx = max(mx, a)
if mx == 0:
    print('NO')
else:
    print('YES', mx)
