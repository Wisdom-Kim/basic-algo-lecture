//
// Created by wisdom99 on 2024-01-10.

#include <iostream>
using namespace std;

const int MX = 10001;
int dat[MX];
int pos=0;

void pop(){
    if(dat[1]!=0) {
        cout<<dat[pos]<<"\n";
        dat[pos--]=0;
    }
    else cout<<-1<<"\n";
}
void size(){
    cout<<pos<<"\n";
}
void push(int n){
    dat[++pos]=n;
}

void empty(){
    (dat[1]==0) ? cout<<1<<"\n" : cout<<0<<"\n";
}

void top(){
    (dat[1]!=0) ? cout<<dat[pos]<<"\n" : cout<<-1<<"\n";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        string cmd;
        cin>>cmd;
        if(cmd=="push"){
            int target;
            cin>>target;
            push(target);
        }
        else if(cmd=="top") top();
        else if(cmd=="empty") empty();
        else if(cmd=="pop") pop();
        else if(cmd=="size") size();
    }
}