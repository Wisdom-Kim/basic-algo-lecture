//
// Created by wisdom99 on 2024-01-08.
//
#include <iostream>
using namespace std;



int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string original,changed;
    int freq['z'-'a'+1]={};
    cin>>original>>changed;

    for(char c:original) freq[c-'a']++;
    for(char c:changed) freq[c-'a']--;

    int ans=0;
    for(auto c:freq) {
       ans+=abs(c);
    }
    cout<<ans;

}