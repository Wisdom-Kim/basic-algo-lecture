//
// Created by wisdom99 on 2024-01-11.
//
#include <iostream>
#include <stack>
using namespace std;
int main(void) {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    stack<int> S;
    int cnt=0;//현재까지 스택에 들어간 최대 수
    string ans;
    int target;
    bool isError=false;
    while(n--) {
        cin>>target;
        while(target>=cnt){
            S.push(++cnt);
            ans.push_back('+');
        }
        if(S.size()==0){
            isError=true;
            break;
        }
        if(target==S.top()){
            ans.push_back('-');
            S.pop();
        }
        else{
            isError=true;
            break;
        }
    }
    if(isError){
        for(auto c:ans) cout<<c<<"\n";
    }
    else cout<<"NO";




}