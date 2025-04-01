"""
https://open.kattis.com/problems/triangelfabriken
Author: https://github.com/smh997/
"""

a, b, c = int(input()), int(input()), int(input())
print('Ratvinklig Triangel' if 90 in [a, b, c] else 'Trubbig Triangel' if list(filter(lambda arg: arg > 90, [a, b, c])) else 'Spetsig Triangel')