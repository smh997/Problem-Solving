/*
 * https://quera.org/problemset/82389/
 * Author: https://github.com/smh997/
 */
#include <bits/stdc++.h>
using namespace std;

struct instruction{
    string type, dest, arg1, arg2, source, address;
    instruction(string _type, string _dest, string _arg1, string _arg2){
        type = _type; dest = _dest; arg1 = _arg1; arg2 = _arg2;
    }
    instruction(string _type, string _dest, string _source){
        type = _type; dest = _dest; source = _source;;
    }
    instruction(string _type, string _address){
        type = _type; address = _address;
    }
};
string ArithBitOp[5] = {"ADD", "AND", "MULT", "OR", "XOR"};
vector<instruction> ins;
vector<unsigned int> IO[103];
unsigned int k, adad;
int numIO = 0;
map<unsigned int, unsigned int> mem;

unsigned int get_value(string address){
    if(address[0] == '$' || address[0] == '#'){
        return (unsigned int)stoul(address.substr(1));
    }
    return mem[(unsigned int)stoul(address.substr(1))];
}

void do_inst(int type, string dest, string arg1, string arg2){
    switch(type){
        case 0:
            mem[get_value(dest)] = ((unsigned int)((arg1[0] == '#')?get_value(arg1):mem[get_value(arg1)]) + (unsigned int)((arg2[0] == '#')?get_value(arg2):mem[get_value(arg2)]));
            break;
        case 1:
            mem[get_value(dest)] = (((arg1[0] == '#')?get_value(arg1):mem[get_value(arg1)]) & ((arg2[0] == '#')?get_value(arg2):mem[get_value(arg2)]));
            break;
        case 2:
            mem[get_value(dest)] = ((unsigned int)((arg1[0] == '#')?get_value(arg1):mem[get_value(arg1)]) * (unsigned int)((arg2[0] == '#')?get_value(arg2):mem[get_value(arg2)]));
            break;
        case 3:
            mem[get_value(dest)] = (((arg1[0] == '#')?get_value(arg1):mem[get_value(arg1)]) | ((arg2[0] == '#')?get_value(arg2):mem[get_value(arg2)]));
            break;
        case 4:
            mem[get_value(dest)] = (((arg1[0] == '#')?get_value(arg1):mem[get_value(arg1)]) ^ ((arg2[0] == '#')?get_value(arg2):mem[get_value(arg2)]));
            break;
    }
}

bool judge(int A, int B, int C, int D, int E){
    int inp;
    for (int i = 0; i < k; ++i) {
        inp = 0;
        mem.clear();
        for (instruction inst: ins) {
            if(inst.type == "INPUT"){
                mem[get_value(inst.address)] = IO[i][inp];
                inp++;
            }
            else if(inst.type == "OUTPUT"){
                if (((inst.address[0]=='#')?get_value(inst.address):mem[get_value(inst.address)]) != IO[i][inp]){
                    return false;
                }
                inp++;
            }
            else if(inst.type == "MOVE"){
                mem[get_value(inst.dest)] = (inst.source[0] == '#')?get_value(inst.source):mem[get_value(inst.source)];
            }
            else{
                if(inst.type == "A"){
                    do_inst(A, inst.dest, inst.arg1, inst.arg2);
                }
                else if(inst.type == "B"){
                    do_inst(B, inst.dest, inst.arg1, inst.arg2);
                }
                else if(inst.type == "C"){
                    do_inst(C, inst.dest, inst.arg1, inst.arg2);
                }
                else if(inst.type == "D"){
                    do_inst(D, inst.dest, inst.arg1, inst.arg2);
                }
                else if(inst.type == "E"){
                    do_inst(E, inst.dest, inst.arg1, inst.arg2);
                }
            }
        }
    }
    return true;
}


int main()
{
    string s, a, b, c;
    while(cin >> s){
        if(s == "OUTPUT"){
            cin >> a;
            ins.push_back(instruction(s, a));
            numIO++;
            break;
        }
        else if(s == "MOVE"){
            cin >> a >> b;
            ins.push_back(instruction(s, a, b));
        }
        else if(s == "INPUT"){
            cin >> a;
            ins.push_back(instruction(s, a));
            numIO++;
        }
        else{
            cin >> a >> b >> c;
            ins.push_back(instruction(s, a, b, c));
        }
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < numIO; ++j) {
            cin >> adad;
            IO[i].push_back(adad);
        }
    }
    int arr[5] = {0, 1, 2, 3, 4};
    vector<vector<string>> res(120);
    int ans = 0;
    do{
        if(judge(arr[0], arr[1], arr[2], arr[3], arr[4])){
            res[ans].push_back(ArithBitOp[arr[0]]);
            res[ans].push_back(ArithBitOp[arr[1]]);
            res[ans].push_back(ArithBitOp[arr[2]]);
            res[ans].push_back(ArithBitOp[arr[3]]);
            res[ans].push_back(ArithBitOp[arr[4]]);
            ans++;
        }
    }while(next_permutation(arr, arr+5));
    cout << ans << endl;
    if(ans == 1){
        for (int i = 0; i < 5; ++i) {
            cout << res[0][i] << ((i==4)?"\n":" ");
        }
    }
    return 0;
}

