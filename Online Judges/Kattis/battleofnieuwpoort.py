"""
Author https://github.com/smh997/
https://open.kattis.com/problems/battleofnieuwpoort
"""

def to_base(d, b):
    digits = "0123456789abcdef"
    ans = ""

    while d > 0:
        r = d % b
        ans = digits[r] + ans
        d //= b

    return ans

inp = input().split()
n = int(inp[0])
for i in range(2, 17):
    ans = to_base(n, i)
    if "00" == ans[-2:]:
        print(i, ans)
        exit(0)
print("Impossible")
