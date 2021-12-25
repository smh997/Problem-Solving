"""
https://open.kattis.com/problems/chopin
Author: https://github.com/smh997/
"""
import sys

di = {'A#': 'Bb', 'Bb': 'A#', 'C#': 'Db', 'Db': 'C#', 'D#': 'Eb', 'Eb': 'D#', 'F#': 'Gb', 'Gb': 'F#', 'G#': 'Ab', 'Ab': 'G#'}
i = 1
lines = sys.stdin.readlines()
for line in lines:
    note, tone = map(str, line.split())
    print('Case ' + str(i) + ': ', end='')
    if note not in di:
        print('UNIQUE')
    else:
        print(di[note], tone)
    i += 1
