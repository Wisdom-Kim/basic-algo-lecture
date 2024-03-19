//
// Created by wisdom99 on 2024-01-14.
//
#include <iostream>
#include <map>

using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;

    map<string,string> pw;
    string site,password;
    while(n--){
        cin>>site>>password;
        pw[site]=password;
    }
    while(m--){
        cin>>site;
        cout<<pw[site]<<"\n";
    }
}