//
// Created by wisdom99 on 2024-02-02.
//
#include <iostream>
#include <stack>
using namespace std;

//한방향만 보는데
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long int ans=0;
    int n; cin>>n;
    stack<long long int> s;
    s.push(1000000001);
    for(int i=1;i<=n;i++){
        int height;
        cin>>height;
        while(s.top()<=height) s.pop();
        ans+=s.size()-1; //기본으로 하나를 가지고 있으므로 -1
        s.push(height);
    }
    cout<<ans;
}