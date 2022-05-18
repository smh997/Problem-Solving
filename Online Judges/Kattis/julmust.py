"""
https://open.kattis.com/problems/julmust
Author: https://github.com/smh997/
"""
R = int(input())
lo, hi, mid, it = 1, R, 0, 1
while True:
    mid = (lo + hi) // 2
    print(it * mid, flush=True)
    inp = input()
    if inp == 'less':
        hi = mid - 1
    elif inp == 'more':
        lo = mid + 1
    else:
        break
    it += 1
