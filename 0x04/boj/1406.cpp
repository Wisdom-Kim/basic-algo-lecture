//
// Created by wisdom99 on 2024-01-08.
//
#include <iostream>
#include <list>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    list <char> L;

    int n;
    string origin;
    cin>>origin; //초기 문자

    for(auto c:origin) L.push_back(c);
    auto t =L.end(); //t는 커서
    cin>>n;
    char target,m;
    while(n--){
        cin >> m;//명령어 입력
        if(m=='P') {
            cin>>target;
            L.insert(t,target);
        }
        else if(m=='L') {if (t != L.begin())  t--;}
        else if(m=='D') {if (t!=L.end())t++;}
        else if(m=='B') {
            if(t!=L.begin()){
                t=L.erase(--t);
            }
        }

    }

    for(auto c:L){
        cout<<c;
    }


}