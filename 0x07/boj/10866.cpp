//
// Created by wisdom99 on 2024-01-11.
//
#include <iostream>

using namespace std;
const int MX=100000;
int dat[2*MX+1];
int head=MX;
int tail=MX;

void push_front(int x){
    dat[--head]=x;
}

void push_back(int x){
    dat[tail++]=x;
}

void pop_front(){
    head==tail ? cout<<-1<<"\n" : cout<<dat[head++]<<"\n";
}

void pop_back(){
    head==tail ? cout<<-1<<"\n" : cout<<dat[--tail]<<"\n";
}

void size(){cout<<tail-head<<"\n";}

void empty(){head==tail ? cout<<1<<"\n" : cout << 0 <<"\n";}

void front(){head==tail? cout<<-1<<"\n" : cout<<dat[head]<<"\n";}

void back(){head==tail? cout<<-1<<"\n" : cout<<dat[tail]<<"\n";}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    while(n--){
        string cmd;
        cin>>cmd;

        if(cmd=="push_front"){
            int target;
            cin>>target;
            push_front(target);
        }
        else if(cmd=="push_back"){
            int target;
            cin>>target;
            push_back(target);
        }
        else if(cmd=="pop_front") pop_front();
        else if(cmd=="pop_back") pop_back();
        else if(cmd=="size") size();
        else if(cmd=="empty") empty();
        else if (cmd=="front") front();
        else back();
    }
}