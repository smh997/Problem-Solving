"""
https://open.kattis.com/problems/exam
Author: https://github.com/smh997/
"""

k = int(input())
me = input()
friend = input()
same = sum([1 for i in range(len(me)) if me[i] == friend[i]]) 
print(len(me) - abs(k - same))
