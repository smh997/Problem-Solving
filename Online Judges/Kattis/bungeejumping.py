"""
https://open.kattis.com/problems/bungeejumping
Author: https://github.com/smh997/
"""
while True:
    k, l, s, w = map(float, input().split())
    if k == l == s == w == 0:
        break
    d = s if s < l else l
    g = 9.81
    t = (2 * d / g) ** 0.5
    v = g * t
    gf = g * w
    dt = 0.0001
    while True:
        if d >= s:
            if v > 10:
                print('Killed by the impact.')
            else:
                print('James Bond survives. ')
            break
        if v < 0:
            print('Stuck in the air.')
            break
        f = gf - k * (d-l if d > l else 0)
        a = f / w
        d += (a * dt * dt / 2) + v * dt
        v += a * dt
