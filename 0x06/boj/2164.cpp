//
// Created by wisdom99 on 2024-01-11.
//
#include <iostream>
using namespace std;

const int MX=1000001;
int dat[MX]; //큐
int first=0;
int tail=0;

void push(int x)
{
    dat[tail++]=x;
}

void pop(){
    if(first==tail) cout<<-1<<"\n";
    else cout<<dat[first++]<<"\n";
}

void size(){
    cout<<tail-first<<"\n";
}

void empty(){
    tail==first ? cout<<1<<"\n" : cout<<0<<"\n";
}

void front(){
    tail==first? cout<<-1<<"\n" : cout<<dat[first]<<"\n";
}

void back(){
    tail==first? cout<<-1<<"\n" : cout<<dat[tail-1]<<"\n";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    while(n--){
        string cmd;
        cin>>cmd;

        if(cmd=="push"){
            int target;
            cin>>target;
            push(target);
        }
        else if(cmd=="pop") pop();
        else if(cmd=="size") size();
        else if(cmd=="empty") empty();
        else if (cmd=="front") front();
        else back();
    }


}