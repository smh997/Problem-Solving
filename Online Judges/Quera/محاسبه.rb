"""
https://quera.org/problemset/52545/
Author: https://github.com/smh997/
"""
i = 0
inp = gets.split
inp = [inp[0].to_i, inp[1].to_i, inp[2].to_i]
m = inp.max
inp = gets.split
inp = [inp[0].to_i, inp[1].to_i, inp[2].to_i]
t = inp.max
if t > m
  m = t
  i = 1
end
inp = gets.split
inp = [inp[0].to_i, inp[1].to_i, inp[2].to_i]
t = inp.max
if t > m
  m = t
  i = 2
end
inp = gets.split
inp = [inp[0].to_i, inp[1].to_i, inp[2].to_i]
t = inp.max
if t > m
  m = t
  i = 3
end
puts (i + 1)