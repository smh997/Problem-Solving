"""
https://quera.org/problemset/33045/
Author: https://github.com/smh997/
"""
def f(a):
    global num
    s = 0
    for i in range(1, a + 1):
        if a % i == 0:
            num += 1
            s += i
    return s


num = 0

if __name__ == "__main__":
    n = int(input())
    res2 = 0;
    for i in range(1, n + 1):
        res2 += f(i)
    print(num, res2)
