//
// Created by wisdom99 on 2024-01-14.
//
#include <iostream>
#include <stack>

using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cnt=0;
    int n; cin>>n;
    while(n--){
        stack<char> S;
        string str;
        cin>>str;
        for(auto c:str){
            if(!S.empty()&& S.top()==c) S.pop();
            else S.push(c);
        }

        if(S.empty()) cnt++;
    }
    cout<<cnt;
}