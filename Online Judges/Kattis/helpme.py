"""
https://open.kattis.com/problems/helpme
Author: https://github.com/smh997/
"""
s = input()
white = []
black = []
for r in reversed(range(8)):
    s = input()
    for i in range(0, len(s)-1, 4):
        if s[i+2] == '.':
            continue
        elif s[i+2] == ':':
            continue
        elif s[i+2].isupper():
            white.append(s[i+2] + str(chr(ord('a') + i // 4)) + str(r+1))
        else:
            black.append(s[i + 2].upper() + str(chr(ord('a') + i // 4)) + str(r + 1))
    s = input()
li = ['K', 'Q', 'R', 'B', 'N', 'P']
white.sort(key=lambda x: x[2])
answ = []
pw = []
ansb = []
pb = []
for ch in li:
    for a in white:
        if ch == a[0]:
            if ch == 'P':
                pw.append(a[1:])
            else:
                answ.append(a)
    for a in black:
        if ch == a[0]:
            if ch == 'P':
                pb.append(a[1:])
            else:
                ansb.append(a)
pw.sort(key=lambda x: x[1])
answ.extend(pw)
ansb.extend(pb)

print('White:', ','.join(answ))
print('Black:', ','.join(ansb))