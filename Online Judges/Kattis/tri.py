"""
https://open.kattis.com/problems/tri
Author: https://github.com/smh997/
"""
a, b, c = map(int, input().split())
if a == b + c:
    print(str(a) + '=' + str(b) + '+' + str(c))
elif a == b - c:
    print(str(a) + '=' + str(b) + '-' + str(c))
elif a == b * c:
    print(str(a) + '=' + str(b) + '*' + str(c))
elif a == b // c:
    print(str(a) + '=' + str(b) + '/' + str(c))
elif a + b == c:
    print(str(a) + '+' + str(b) + '=' + str(c))
elif a - b == c:
    print(str(a) + '-' + str(b) + '=' + str(c))
elif a * b == c:
    print(str(a) + '*' + str(b) + '=' + str(c))
else:
    print(str(a) + '/' + str(b) + '=' + str(c))
