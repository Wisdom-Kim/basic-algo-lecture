//
// Created by wisdom99 on 2024-01-14.
//
// ()에서는 top만큼 더하고, )에서는 1개 더하고 pop하기

#include <iostream>
#include <stack>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bool isClosed=false; //아까 막 닫혔는지
    stack<char> S; //괄호열
    stack<int> ans; //붙어있지 않는 괄호열 값들
    string str; cin>>str;
    int cnt=1;//단일 괄호열 값
    bool isValid=true;

    for(auto c:str){
        if(c=='(' || c=='[') {
            S.push(c);
            if(isClosed){
                isClosed=false;
                //새로운 괄호열을 맞을 준비
                ans.push(cnt);
                cnt=1;
            }
        }
        else if(c==')'){
            if(!S.empty() && S.top()=='('){
                S.pop();
                cnt*=2;
                isClosed=true;
            }
            else{
                isValid=false;
                break;
            }
        }
        else if(c==']'){
            if(!S.empty() && S.top()=='['){
                S.pop();
                cnt*=3;
                isClosed=true;
            }
            else{
                isValid=false;
                break;
            }
        }
    }
    ans.push(cnt);
    if(isValid){
        int result=0;
        while(!ans.empty()){
            result+=ans.top();
            ans.pop();
        }
        cout<<result;
    }
    else cout<<0;

}
