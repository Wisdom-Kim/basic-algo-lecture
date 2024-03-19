//
// Created by wisdom99 on 2024-02-02
//
#include <iostream>
#include <stack>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; cin>>n;
    int arr[n];
    int ans[n];
    stack<pair<int,int>> s; //{인덱스,값}
    for(int i=0;i<n;i++)cin>>arr[i];
    s.push({n,-1});
    for(int i=n-1;i>=0;i--){
        s.push({i,arr[i]});
        if(arr[i]<s.top().second){
            //오큰수를 발견한 경우
            ans[i]=s.top().second;
        }
    }

}