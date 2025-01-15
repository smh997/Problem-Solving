inp = input()
p = '0'
for i in range(len(inp)):
    if inp[i] != p:
        print(inp[i], end='')
    p = inp[i]
