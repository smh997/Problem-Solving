"""
https://open.kattis.com/problems/wordlefeedback
Author: https://github.com/smh997/
"""

truth = input()
guess = input()
ans = ['-' for i in range(5)]
for i in range(5):
    if truth[i] == guess[i]:
        ans[i] = 'G'
for i in range(5):
    if guess[i] != truth[i] and guess[i] in truth:
        c = truth.count(guess[i])
        for j in range(5):
            if guess[j] == guess[i] == truth[j]:
                c -= 1
        for j in range(i):
            if guess[j] != truth[j] and guess[j] == guess[i]:
                c -= 1
        if c > 0:
            ans[i] = 'Y'
    
print(''.join(ans))