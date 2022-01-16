"""
https://open.kattis.com/problems/tenis
Author: https://github.com/smh997/
"""
a, b = map(str, input().split())
n = int(input())
for i in range(n):
    li = input().split()
    if len(li) not in [2, 3]:
        print('ne')
        continue
    flagf = False
    if a == 'federer':
        for s in range(len(li)):
            aa, bb = map(int, li[s].split(':'))
            if aa < bb:
                print('ne')
                flagf = True
                break
        if flagf:
            continue
    elif b == 'federer':
        for s in range(len(li)):
            aa, bb = map(int, li[s].split(':'))
            if aa > bb:
                print('ne')
                flagf = True
                break
        if flagf:
            continue
    sa, sb = 0, 0
    for s in range(2):
        aa, bb = map(int, li[s].split(':'))
        if aa > 7 or bb > 7:
            print('ne')
            flagf = True
            break
        if (aa == 6 and aa >= bb + 2) or (aa == 7 and (bb == 5 or bb == 6)):
            sa += 1
        elif (bb == 6 and bb >= aa + 2) or ((aa == 5 or aa == 6) and bb == 7):
            sb += 1
        else:
            print('ne')
            flagf = True
            break
    if flagf:
        continue
    if sa == sb and len(li) == 2:
        print('ne')
        continue
    if sa != sb:
        if len(li) == 3:
            print('ne')
        else:
            print('da')
        continue
    aa, bb = map(int, li[2].split(':'))
    if (aa > 6 and aa == bb + 2) or (aa == 6 and aa >= bb+2):
        sa += 1
    elif (bb > 6 and bb == aa + 2) or (bb == 6 and bb >= aa+2):
        sb += 1
    else:
        print('ne')
        continue
    print('da')
