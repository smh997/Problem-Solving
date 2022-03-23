"""
https://quera.org/problemset/127291/
Author: https://github.com/smh997/
"""
t = int(input())
for _ in range(t):
    di = [0] * 6
    s = input()
    for ch in s:
        di[ord(ch) - ord('A')] += 1
    for i in range(3):
        di[i] -= di[i + 3]
    A, B, C = di[0], di[1], di[2]
    if A > 0 and B > 0 and C > 0:
        v = min(abs(A), abs(C))
        B += v
        A -= v
        C -= v
    elif A > 0 and B > 0 and C < 0:
        v = min(abs(B), abs(C))
        B -= v
        A += v
        C += v
    elif A > 0 and B < 0 and C > 0:
        v = min(abs(A), abs(C))
        B += v
        A -= v
        C -= v
        if B < 0:
            if A:
                vv = min(abs(A), abs(B))
                C -= vv
                A -= vv
                B += vv
            elif C:
                vv = min(abs(C), abs(B))
                C -= vv
                A -= vv
                B += vv
    elif A > 0 and B < 0 and C < 0:
        v = min(abs(A), abs(B))
        B += v
        A -= v
        C -= v
    elif A < 0 and B > 0 and C > 0:
        v = min(abs(A), abs(B))
        B -= v
        A += v
        C += v
    elif A < 0 and B > 0 and C < 0:
        v = min(abs(A), abs(C))
        B -= v
        A += v
        C += v
        if B > 0:
            if A:
                vv = min(abs(A), abs(B))
                C += vv
                B -= vv
                A += vv
            elif C:
                vv = min(abs(C), abs(B))
                C += vv
                B -= vv
                A += vv
    elif A < 0 and B < 0 and C > 0:
        v = min(abs(B), abs(C))
        B += v
        A -= v
        C -= v
    elif A < 0 and B < 0 and C < 0:
        v = min(abs(A), abs(C))
        B -= v
        A += v
        C += v
    elif A == 0 and B > 0 and C < 0:
        v = min(abs(B), abs(C))
        B -= v
        A += v
        C += v
    elif A == 0 and C > 0 and B < 0:
        v = min(abs(B), abs(C))
        B += v
        A -= v
        C -= v
    elif B == 0 and C > 0 and A > 0:
        v = min(abs(A), abs(C))
        B += v
        A -= v
        C -= v
    elif B == 0 and C < 0 and A < 0:
        v = min(abs(A), abs(C))
        B -= v
        A += v
        C += v
    elif C == 0 and A > 0 and B < 0:
        v = min(abs(A), abs(B))
        B += v
        A -= v
        C -= v
    elif C == 0 and B > 0 and A < 0:
        v = min(abs(A), abs(B))
        B -= v
        A += v
        C += v

    print(abs(A) + abs(B) + abs(C))
    