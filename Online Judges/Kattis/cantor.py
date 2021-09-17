"""
https://open.kattis.com/problems/cantor
Author: https://github.com/smh997/
"""
if __name__ == "__main__":
    while True:
        s = input()
        if s == "END":
            break
        x = float(s)
        if x == 0 or x == 1:
            print("MEMBER")
            continue
        seen = set()
        member = True
        while x not in seen:
            seen.add(x)
            x *= 3
           # print("%.6f" % x)
            if int(x) == 1:
                print("NON-MEMBER")
                member = False
                break
            x = round(x - int(x),6)
       # print(seen)
        if member:
            print("MEMBER")