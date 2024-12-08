n = int(input())
li = [input() for _ in range(n)]
a, b = 'kjuklingur', 'nautakjot'
print('blandad best' if a in li and b in li else a if a in li else b)