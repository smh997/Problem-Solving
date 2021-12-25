"""
https://open.kattis.com/problems/ostgotska
Author: https://github.com/smh997/
"""
li = input().split()
print('dae ae ju traeligt va' if len([a for a in li if 'ae' in a])/len(li) >= 0.4 else 'haer talar vi rikssvenska')