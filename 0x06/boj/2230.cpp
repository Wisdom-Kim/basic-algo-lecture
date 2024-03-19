//
// Created by wisdom99 on 2024-01-12.
//
#include<iostream>
#include <algorithm>
#include <list>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    string see[m];//보도 못한 사람
    string hear[n];//듣도 못한사람;
    for(int i=0;i<n;i++)cin>>hear[i];
    for(int i=0;i<m;i++)cin>>see[i];
    list<string> ans;
    sort(see,see+m);
    sort(hear,hear+n);

    for(auto h:hear){
        for(auto s:see){
            if(s==h) ans.push_back(s);
        }
    }
    cout<<ans.size()<<"\n";
    for(auto name:ans) cout<<name<<"\n";


}