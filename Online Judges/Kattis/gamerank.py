"""
https://open.kattis.com/problems/gamerank
Author: https://github.com/smh997/
"""
s = input()
li = [0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2]
rank = 25
stars = 0
consecute = 0
n = len(s)
for i in range(n):
    # print(rank, stars, consecute)
    if s[i] == 'W':
        consecute += 1
        if stars == li[rank]:
            if 6 <= rank <= 25 and consecute >= 3:
                stars = 2
            else:
                stars = 1
            rank -= 1
        elif stars == li[rank]-1 and 6 <= rank <= 25 and consecute >= 3:
            stars = 1
            rank -= 1
        else:
            if 6 <= rank <= 25 and consecute >= 3:
                stars += 2
            else:
                stars += 1
        if rank == 0:
            break
    else:
        consecute = 0
        if rank > 20:
            continue
        if rank < 20 and stars == 0:
            rank += 1
            stars = li[rank] - 1
        else:
            if rank == 20 and stars == 0:
                continue
            stars -= 1
print(rank if rank else 'Legend')


