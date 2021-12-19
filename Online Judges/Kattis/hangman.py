"""
https://open.kattis.com/problems/hangman
Author: https://github.com/smh997/
"""
target = input()
s = input()
li = {}
for i in range(len(target)):
    li[target[i]] = target.count(target[i])
c = 0
done = 0
for ch in s:
    if ch not in li:
        c += 1
        if c == 10:
            print('LOSE')
            break
    else:
        done += li[ch]
        if done == len(target):
            print('WIN')
            break
