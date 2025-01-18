"""
https://open.kattis.com/problems/bitbybit
Author: https://github.com/smh997/
"""

n = int(input())
while(n != 0):
    ans = ['?' for i in range(32)]
    for i in range(n):
        ins_list = input().split()
        if ins_list[0] == 'SET':
            ans[31 - int(ins_list[1])] = '1'
        elif ins_list[0] == 'CLEAR':
            ans[31 - int(ins_list[1])] = '0'
        elif ins_list[0] == 'AND':
            if ans[31 - int(ins_list[1])] == '0' or ans[31 - int(ins_list[2])] == '0':
                ans[31 - int(ins_list[1])] = '0'
            elif ans[31 - int(ins_list[1])] == '1' and ans[31 - int(ins_list[2])] == '1':
                ans[31 - int(ins_list[1])] = '1'
            else:
                ans[31 - int(ins_list[1])] = '?'
        else:
            if ans[31 - int(ins_list[1])] == '1' or ans[31 - int(ins_list[2])] == '1':
                ans[31 - int(ins_list[1])] = '1'
            elif ans[31 - int(ins_list[1])] == '0' and ans[31 - int(ins_list[2])] == '0':
                ans[31 - int(ins_list[1])] = '0'
            else:
                ans[31 - int(ins_list[1])] = '?'
        # print(ans)
    print(''.join(ans))
    n = int(input())
