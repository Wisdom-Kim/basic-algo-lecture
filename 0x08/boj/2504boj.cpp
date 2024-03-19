//
// Created by wisdom99 on 2024-01-14.
//
#include <iostream>
#include <stack>

using namespace std;

int main(void){

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    string str;
    cin>>str;

    int now=1;//단일 괄호열 값
    int result=0;
    bool isValid=true;
    stack<char> s;
    for(int i=0;i<str.length();i++){
        char c=str[i];
        if(c=='(') {
            s.push(c);
            now*=2;
        }
        else if(c=='['){
            s.push(c);
            now*=3;
        }
        else if(c==')'){
            if(s.empty()||s.top()!='('){
                isValid=false;
                break;
            }
            if(str[i-1]=='(') result+=now;
            s.pop();
            now/=2;
        }
        else if(c==']'){
            if(s.empty()||s.top()!='['){
                isValid=false;
                break;
            }
            if(str[i-1]=='[') result+=now;
            s.pop();
            now/=3;
        }
    }
    if(!s.empty()) isValid=false;
    (isValid)? cout<<result : cout<<0;
}

//)( or )[ or ]( or ][ or str.end();
//(()[[]]); (()[()][(())]])