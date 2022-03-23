"""
https://quera.org/problemset/52549/
Author: https://github.com/smh997/
"""
n = gets.to_i
a = [0] * 1000001
b = []
while true
    b = []
    if n==0
        break
    end
    
    for i in (1..n)
        inp = gets.split
        d = inp[0].to_i
        for i in (1..d)
            a[inp[i].to_i] += 3 - i + 1
        end
    end
    m = 0
    for i in (1..1000000)
        if m < a[i]
            m = a[i]
        end
    end
    for i in (1..1000000)
        if m == a[i]
            b << i
        end
        a[i] = 0
    end
    for c in (0..b.size)
        print b[c]
        print ' '
    end
    puts ""
    n = gets.to_i
end