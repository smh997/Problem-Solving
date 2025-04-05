"""
https://open.kattis.com/problems/lastminute
Author: https://github.com/smh997/
"""

au, bu, ar, br = map(int, input().split())
print(ar * br + (au if br else 0) + (bu if ar else 0) + (min(au, bu) if ar + br == 0 else 0))