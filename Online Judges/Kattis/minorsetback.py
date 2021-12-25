"""
https://open.kattis.com/problems/minorsetback
Author: https://github.com/smh997/
"""
if __name__ == "__main__":
    fp = {
        440.0: 'A',
        466.1637615180899: 'Bb',
        493.8833012561241: 'B',
        523.2511306011972: 'C',
        554.3652619537442: 'C#',
        587.3295358348151: 'D',
        622.2539674441618: 'Eb',
        659.2551138257398: 'E',
        698.4564628660078: 'F',
        739.9888454232688: 'F#',
        783.9908719634985: 'G',
        830.6093951598903: 'G#'
    }
    freqs  = []
    N = int(input())
    for _ in range(N):
        x = float(input())
        while x < 440:
            x *= 2
        while x >= 880:
            x /= 2
        for f, c in fp.items():
            if abs(x - f) <= 0.0001:
                freqs.append(c)
    mk = {
        'G major': {'G', 'A', 'B', 'C', 'D', 'E', 'F#'},
        'C major': {'C', 'D', 'E', 'F', 'G', 'A', 'B'},
        'Eb major': {'Eb', 'F', 'G', 'G#', 'Bb', 'C', 'D'},
        'F# minor': {'F#', 'G#', 'A', 'B', 'C#', 'D', 'E'},
        'G minor': {'G', 'A', 'Bb', 'C', 'D', 'Eb', 'F'}
    }
    count, g = 0, None
    for key, value in mk.items():
        if len(set(freqs) - value) == 0:
            g = key
            count +=1 
    if count == 1:
        print(g)
        for it in freqs:
            print('Ab' if g == 'Eb major' and it == 'G#' else it)
    else:
        print('cannot determine key')
