word = input()
if len(word) < 4:
    print('Neibb')
else:
    print('Jebb' if ('brr' + (len(word) - 4) * 'r') == word[:len(word)-1] and word[-1] in ['a', 'e', 'i', 'o', 'u', 'y'] else 'Neibb')