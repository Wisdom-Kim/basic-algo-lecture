//
// Created by wisdom99 on 2024-03-19.
//
#include<iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string origin;
    string target;
    getline(cin,origin);
    getline(cin,target);

    int cnt =0 ; //정답
    while(origin.find(target)!=string::npos){
        int firstIdx = origin.find(target); cnt++;
        origin = origin.substr(firstIdx+target.length(),origin.length());
    }
    cout<<cnt;


}