"""
https://quera.org/problemset/3416/
Author: https://github.com/smh997/
"""
n = int(input())
for i in range(n):
    if int(input()) == 1:
        s = input()
        c = s[0]
        co = 1
        for j in range(1, len(s)):
            if s[j] != s[j - 1]:
                print(s[j - 1], end='')
                if co > 1:
                    print(co, end='')
                co = 1
            else:
                co += 1
        print(s[len(s) - 1], end='')
        if co > 1:
            print(co)
        else:
            print("")
    else:
        s = input()
        t = 0
        c = ''
        ind = 0
        while t != len(s):
            c = s[t]
            ind = t + 1
            num = ""
            while ind < len(s) and s[ind].isdigit():
                num += s[ind]
                ind += 1
            if num == "":
                print(c, end='')
            else:
                for k in range(int(num)):
                    print(c, end='')
            t = ind
        print("")
