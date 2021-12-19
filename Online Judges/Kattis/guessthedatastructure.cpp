/*
 * https://open.kattis.com/problems/guessthedatastructure
 * Author: https://github.com/smh997/
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;
    bool ss,qq,pqpq;
    while(cin>>n){
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        ss = true;
        qq = true;
        pqpq = true;
        for (int i = 0; i < n; ++i) {
            cin>>a>>b;
            if(a==1){
                s.push(b);
                q.push(b);
                pq.push(b);
            }
            else{
                if(s.empty() || s.top()!=b){
                    ss = false;
                }
                if(!s.empty())s.pop();
                if(q.empty() || q.front()!=b){
                    qq = false;
                }
                if(!q.empty())q.pop();
                if(pq.empty() || pq.top()!=b){
                    pqpq = false;
                }
                if(!pq.empty())pq.pop();
            }
        }
        if((ss&&qq)||(ss&&pqpq)||(qq&&pqpq)){
            cout<<"not sure"<<endl;
        }
        else if(ss){
            cout<<"stack"<<endl;
        }
        else if(qq){
            cout<<"queue"<<endl;
        }
        else if(pqpq){
            cout<<"priority queue"<<endl;
        }
        else{
            cout<<"impossible"<<endl;
        }
    }
}
