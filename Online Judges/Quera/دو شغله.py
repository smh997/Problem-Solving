"""
https://quera.org/problemset/111990/
Author: https://github.com/smh997/
"""
pers, bah = {'shanbe', 'doshanbe', 'chaharshanbe'}, {'yekshanbe', 'seshanbe', 'panjshanbe'}
day = input()
print('perspolis' if day in pers else 'bahman' if day in bah else 'tatil')
