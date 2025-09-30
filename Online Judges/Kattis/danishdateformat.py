"""
Author https://github.com/smh997/
https://open.kattis.com/problems/danishdateformat
"""

m, d, y = map(int, input().split('/'))
mo = ['januar', 'februar', 'marts', 'april', 'maj', 'juni', 'juli', 'august', 'september', 'oktober', 'november', 'december']
print(f'{d}. {mo[m-1]} {y}')
