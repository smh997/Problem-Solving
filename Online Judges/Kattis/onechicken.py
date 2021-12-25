"""
https://open.kattis.com/problems/onechicken
Author: https://github.com/smh997/
"""
a, b = map(int, input().split())
print('Dr. Chaz will have %d pieces of chicken left over!' %(b-a) if b > a+1 else 'Dr. Chaz will have 1 piece of chicken left over!' if b-a==1 else 'Dr. Chaz needs 1 more piece of chicken!' if a-b==1 else 'Dr. Chaz needs %d more pieces of chicken!'  %(a-b))