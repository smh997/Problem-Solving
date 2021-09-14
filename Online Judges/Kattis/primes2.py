"""
https://open.kattis.com/problems/primes2
Author: https://github.com/smh997/
"""
from math import sqrt


def gcd(a: int, b: int):
    a, b = max(a, b), min(a, b)
    if b == 0:
        return a
    return gcd(b, a % b)

def fraction_xy(x: int, y: int):
    gcd_ = gcd(x, y)
    return x//gcd_, y//gcd_

def belongs(num: str, collection: list):
    for char in num:
        if char not in collection:
            return False
    return True

def prime(a: int):
    if a == 0 or a == 1:
        return False
    for i in range(2, int(sqrt(a))+1):
        if a % i == 0:
            return False
    return True

if __name__ == "__main__":
    bin_ = ['0', '1']
    octal_ = ['0', '1', '2', '3', '4', '5', '6', '7']
    decimal_ = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    hex_ = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']
    T = int(input())
    for _ in range(T):
        num = input()
        prob, cnt = 0, 0
        if belongs(num, bin_):
            cnt += 1
            if(prime(int(num, 2))):
                prob += 1
        if belongs(num, octal_):
            cnt += 1
            if(prime(int(num, 8))):
                prob += 1
        if belongs(num, decimal_):
            cnt += 1
            if(prime(int(num))):
                prob += 1
        if belongs(num, hex_):
            cnt += 1
            if(prime(int(num, 16))):
                prob += 1
        print('/'.join(map(str, fraction_xy(prob, cnt))))

