"""
https://quera.org/problemset/110015/
Author: https://github.com/smh997/
"""
emp = '.......'
default = 'ghorfe'
k = int(input())
args = ''
for i in range(1, k + 1):
    args += 'default + str({})'.format(i)
    args += '' if i == k else ', '
for i in range(8-k):
    args += ', ' if k or i else ''
    args += 'emp'
args = eval(args)
print('########.......########\n#{}.......{}#\n########.......########\n#{}.......{}#\n########.......########\n#{}.......{}#\n########.......########\n#{}.......{}#\n#######################'.format(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7]))
