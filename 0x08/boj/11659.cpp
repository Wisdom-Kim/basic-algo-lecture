//
// Created by wisdom99 on 2024-01-14.
//
#include <iostream>

using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    int arr[n+1];
    for(int i=1;i<n+1;i++)cin>>arr[i];

    arr[0]=0;
    //구간합 만들기
    for(int i=2;i<n+1;i++){
        arr[i]+=arr[i-1];
    }

    while(m--){
        int i,j;
        cin>>i>>j;
        cout<<arr[j]-arr[--i]<<"\n";
    }
}