n = int(input())
li = [input().lower() for _ in range(n)]
inp = input().split()
for a in inp:
    if a.lower() not in li:
        print('Thore has left the chat')
        exit(0)
print('Hi, how do I look today?')