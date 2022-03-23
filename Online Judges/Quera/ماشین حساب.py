"""
https://quera.org/problemset/123806/
Author: https://github.com/smh997/
"""
inp = input()
order = []
mosbat = []
manfi = []
res = 0
i = 0
while i < len(inp):
    if inp[i] == '+':
        j = i + 1
        while j < len(inp):
            j += 1
            if j == len(inp) or inp[j] in ['+', '-']:
                break
        adad = inp[i+1:j]
        i = j
        mosbat.append(int(adad))
    elif inp[i] == '-':
        j = i + 1
        while j < len(inp):
            j += 1
            if j == len(inp) or inp[j] in ['+', '-']:
                break
        adad = inp[i + 1:j]
        i = j
        manfi.append(-int(adad))
mosbat.sort(reverse=True)
manfi.sort(reverse=True)
if len(mosbat) == len(manfi):
    for i in range(len(mosbat)):
        res += mosbat[i] + manfi[i]
        order.append('+' + str(mosbat[i]))
        order.append('-' + str(-manfi[i]))
elif len(mosbat) > len(manfi):
    for i in range(len(manfi)):
        res += mosbat[i] + manfi[i]
        order.append('+' + str(mosbat[i]))
        order.append('-' + str(-manfi[i]))
    if mosbat[len(manfi)] > res:
        res -= mosbat[len(manfi)]
        order.append('-' + str(mosbat[len(manfi)]))
        for i in range(len(manfi) + 1, len(mosbat)):
            res += mosbat[i]
            order.append('+' + str(mosbat[i]))
    else:
        for i in range(len(manfi), len(mosbat)):
            res += mosbat[i]
            order.append('+' + str(mosbat[i]))
else:
    for i in range(len(mosbat)):
        res += mosbat[i] + manfi[i]
        order.append('+' + str(mosbat[i]))
        order.append('-' + str(-manfi[i]))
    if res < 0:
        res -= manfi[len(manfi) - 1]
        order.append('+' + str(-manfi[len(manfi) - 1]))
        for i in range(len(mosbat), len(manfi) - 1):
            res += manfi[i]
            order.append('-' + str(-manfi[i]))
    else:
        for i in range(len(mosbat), len(manfi)):
            res += manfi[i]
            order.append('-' + str(-manfi[i]))
print(''.join(order) + f'={res}')