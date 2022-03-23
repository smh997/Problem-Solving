"""
https://quera.org/problemset/62451/
Author: https://github.com/smh997/
"""
x1 = int(input())
v1 = int(input())
x2 = int(input())
v2 = int(input())
if v1 == v2:
    print('WAIT WAIT')
elif v1 == 0:
    if v2 > 0:
        if x2 < x1:
            print('SEE YOU')
        else:
            print('BORO BORO')
    else:
        if x2 < x1:
            print('BORO BORO')
        else:
            print('SEE YOU')
elif v2 == 0:
    if v1 > 0:
        if x1 < x2:
            print('SEE YOU')
        else:
            print('BORO BORO')
    else:
        if x1 < x2:
            print('BORO BORO')
        else:
            print('SEE YOU')
elif x1 < x2:
    if v1 * v2 > 0:
        if v1 < v2:
            print('BORO BORO')
        else:
            print('SEE YOU')
    else:
        if v1 < 0:
            print('BORO BORO')
        else:
            print('SEE YOU')
else:
    if v1 * v2 > 0:
        if v2 < v1:
            print('BORO BORO')
        else:
            print('SEE YOU')
    else:
        if v2 < 0:
            print('BORO BORO')
        else:
            print('SEE YOU')