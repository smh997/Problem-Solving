"""
https://quera.org/problemset/2757/
Author: https://github.com/smh997/
"""
import math


def aval(a):
    for i in range(2, int(math.sqrt(a)) + 1):
        if a % i == 0:
            return False
    return True


if __name__ == "__main__":
    k = int(input())
    s = set()
    div = 2
    while not aval(k):
        # print("d: " + str(div) + " k: " + str(k))
        if k % div == 0:
            k //= div
            s.add(div)
        else:
            div += 1
            while not aval(div):
                div += 1
    s.add(k)
    p = 1
    for a in s:
        p *= a
    print(p)
