"""
https://open.kattis.com/problems/kitchencombinatorics
Author: https://github.com/smh997/
"""
if __name__ == '__main__':
    r, s, m, d, n = map(int, input().split())
    ingredient_brands = []
    ingredient_brands = list(map(int, input().split()))
    starter, main, dessert = [], [], []
    for i in range(s):
        this_dish = list(map(int, input().split()))[1:]
        this_dish = set(this_dish)
        starter.append(this_dish)
    for i in range(m):
        this_dish = list(map(int, input().split()))[1:]
        this_dish = set(this_dish)
        main.append(this_dish)
    for i in range(d):
        this_dish = list(map(int, input().split()))[1:]
        this_dish = set(this_dish)
        dessert.append(this_dish)
    incompatible = set()
    for i in range(n):
        incompatible.add(' '.join(str(i - 1) for i in sorted(list(map(int, input().split())))))
    ans = 0
    for sti in range(len(starter)):
        for mai in range(len(main)):
            for dei in range(len(dessert)):
                if ' '.join(str(i) for i in sorted([sti, mai + len(starter)])) in incompatible:
                    continue
                if ' '.join(str(i) for i in sorted([sti, dei + len(starter) + len(main)])) in incompatible:
                    continue
                if ' '.join(str(i) for i in sorted([mai + len(starter), dei + len(starter) + len(main)])) in incompatible:
                    continue
                needed = starter[sti].union(main[mai]).union(dessert[dei])
                p = 1
                for i in needed:
                    p *= ingredient_brands[i - 1]
                ans += p
                if ans > int(1e18):
                    print('too many')
                    exit(0)
    print(ans)