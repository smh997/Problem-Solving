"""
https://quera.org/problemset/2433/
Author: https://github.com/smh997/
"""
import re
try:
    while True:
        line = input()
        tar = re.search("(\s)*([+-]?([0-9]+)(\.[0-9]+)?((e|E)([+-]?([0-9]*)|0))?)(\s)*", line)
        if tar != None:
            if tar.group() == line:
                print("LEGAL")
            else:
                print("ILLEGAL")
        else:
            print("ILLEGAL")
except:
    pass