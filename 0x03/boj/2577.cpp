//
// Created by wisdom99 on 2024-01-06.
//
#include <iostream>

using namespace std;

int freq[10];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a,b,c;
    cin>>a>>b>>c;
    long int result = a*b*c;
    for(char c:to_string(result)){
       freq[c-'0']++;
    }
    for(int i:freq)
        cout<<i<<"\n";

}