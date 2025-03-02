"""
https://open.kattis.com/problems/countthevowels
Author: https://github.com/smh997/
"""

inp = input()
ans = 0
for ch in inp:
    if ch in ['A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u']:
        ans += 1
print(ans)