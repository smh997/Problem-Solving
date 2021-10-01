"""
https://open.kattis.com/problems/eligibility
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    name, post, birth, course = map(str, input().split())
    if int(post[:4]) >= 2010 or int(birth[:4]) >= 1991:
        print(name, 'eligible')
    elif int(course) >= 41:
        print(name, 'ineligible')
    else:
        print(name, 'coach petitions')
