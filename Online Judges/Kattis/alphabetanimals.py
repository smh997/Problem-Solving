"""
https://open.kattis.com/problems/alphabetanimals
Author: https://github.com/smh997/
"""
di = {'a':[], 'b':[], 'c':[], 'd':[], 'e':[], 'f':[], 'g':[], 'h':[], 'i':[], 'j':[], 'k':[], 'l':[], 'm':[], 'n':[], 'o':[], 'p':[], 'q':[], 'r':[], 's':[], 't':[], 'u':[], 'v':[], 'w':[], 'x':[], 'y':[], 'z':[]}
p = input()
n = int(input())
s = []
t = []
for i in range(n):
    inp = input()
    di[inp[0]].append(inp)
if len(di[p[len(p)-1]]) != 0:
    for a in di[p[len(p)-1]]:
        if len(di[a[len(a)-1]]) == 0 or (len(di[a[len(a)-1]]) == 1 and a[len(a)-1] == p[len(p)-1]):
            print("%s!" % a)
            exit(0)
    print(di[p[len(p) - 1]][0])
else:
    print('?')