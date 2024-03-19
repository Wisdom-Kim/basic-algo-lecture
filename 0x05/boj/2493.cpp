//
// Created by wisdom99 on 2024-02-01.
//
#include <iostream>
#include <stack>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    stack<pair<int,int>> s; //pair는 {높이,인덱스}로 이루어짐
    int n; cin>>n;
    s.push({100000001,0});
    for(int i=1;i<=n;i++){
        int height;
        cin>>height;
        //나보다 큰게 나올때까지 pop한다
        while(s.top().first<height) s.pop();
        cout<<s.top().second<<" ";
        s.push({height,i});
    }

}