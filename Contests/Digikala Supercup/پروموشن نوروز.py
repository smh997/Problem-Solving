# https://quera.org/problemset/136480/
n = int(input())
for i in range(n):
    s = input()
    flag = True
    for j in reversed(range(1, len(s))):
        if s[j] > s[j-1]:
            res = s[0:j-1]
            li = [s[j]]
            mch = s[j]
            for ch in s[j+1:]:
                if ch > s[j-1]:
                    if ch < mch:
                        mch = ch
                li.append(ch)
            li.remove(mch)
            res += mch
            for ch in sorted([s[j-1]] + li):
                res += ch
            print(res)
            flag = False
            break
    if flag:
        print('no answer')
