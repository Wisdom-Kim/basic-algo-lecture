//
// Created by wisdom99 on 2024-01-08.
//
#include<iostream>

int freq[201];
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,v,number;
    cin>>n;
    while(n--){
        cin>>number;
        freq[100+number]++;
    }
    cin>>v;
    cout<<freq[100+v];
}