"""
https://open.kattis.com/problems/dicegame
Author: https://github.com/smh997/
"""
gun = sum(list(map(int, input().split())))
emma = sum(list(map(int, input().split())))
if gun > emma:
    print('Gunnar')
elif gun < emma:
    print('Emma')
else:
    print('Tie')