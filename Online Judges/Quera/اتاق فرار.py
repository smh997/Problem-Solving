"""
https://quera.org/problemset/123801/
Author: https://github.com/smh997/
"""
bala = list(map(int, input().split()))
paein = list(map(int, input().split()))
for i in range(5):
    for j in range(5):
        a = bala[i % 5] + paein[j % 5]
        b = bala[(i + 1) % 5] + paein[(j + 1) % 5]
        c = bala[(i + 2) % 5] + paein[(j + 2) % 5]
        adad = (a % 10) * 100 + (b % 10) * 10 + (c % 10)
        if adad % 6 == 0:
            print('Boro joloo :)')
            exit(0)
print('Gir oftadi :(')