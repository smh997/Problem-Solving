"""
https://open.kattis.com/problems/roundedbuttons
Author: https://github.com/smh997/
"""
t = int(input())
for _ in range(t):
    li = list(map(float, input().split()))
    x, y, w, h, r = li[0], li[1], li[2], li[3], li[4]
    circles = [(x+r, y+r), (x+w-r, y+r), (x+r, y+h-r), (x+w-r, y+h-r)]
    m = int(li[5])
    for j in range(6, 2*m+6, 2):
        px, py = li[j], li[j+1]
        if px < x or px > x+w or py < y or py > y+h:
            print('outside')
            continue
        if x <= px <= circles[0][0] and y <= py <= circles[0][1]:
            if (px-circles[0][0])**2 + (py-circles[0][1])**2 > r*r:
                print('outside')
                continue
        elif circles[1][0] <= px <= x+w and y <= py <= circles[1][1]:
            if (px-circles[1][0])**2 + (py-circles[1][1])**2 > r*r:
                print('outside')
                continue
        elif x <= px <= circles[2][0] and circles[2][1] <= py <= y+h:
            if (px-circles[2][0])**2 + (py-circles[2][1])**2 > r*r:
                print('outside')
                continue
        elif circles[3][0] <= px <= x+w and circles[3][1] <= py <= y+h:
            if (px-circles[3][0])**2 + (py-circles[3][1])**2 > r*r:
                print('outside')
                continue
        print('inside')
    if _ != t-1:
        print()

