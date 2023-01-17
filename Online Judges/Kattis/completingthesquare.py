"""
https://open.kattis.com/problems/completingthesquare
Author: https://github.com/smh997/
"""

def get_distance(p1, p2):
    return ((p1[0] - p2[0]) ** 2 +  (p1[1] - p2[1]) ** 2) ** 0.5

def get_vector(p1, p2):
    return (p2[0] - p1[0], p2[1] - p1[1])

def get_sum(v1, v2):
    return (v1[0] + v2[0], v1[1] + v2[1])

corners = [tuple(map(int, input().split())) for _ in range(3)]

if get_distance(corners[0], corners[1]) == get_distance(corners[0], corners[2]):
    c = corners[0]
    v = get_sum(get_vector(corners[0], corners[1]), get_vector(corners[0], corners[2]))
elif get_distance(corners[0], corners[1]) < get_distance(corners[0], corners[2]):
    c = corners[1]
    v = get_sum(get_vector(corners[1], corners[0]), get_vector(corners[1], corners[2]))
else:
    c = corners[2]
    v = get_sum(get_vector(corners[2], corners[0]), get_vector(corners[2], corners[1]))

res = get_sum(c, v)
print(f'{res[0]} {res[1]}')
