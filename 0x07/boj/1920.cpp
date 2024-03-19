//
// Created by wisdom99 on 2024-01-11.
//
#include <iostream>
#include <algorithm>
using namespace std;

bool binarySearch(int arr[],int target,int start, int end){
    int mid =(start+end)/2;
    if(start>end) return false;

    if(arr[mid]>target) return binarySearch(arr,target,start,mid-1);
    else if (arr[mid]<target) return binarySearch(arr,target,mid+1,end);
    else return true;
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    int target;
    cin>>n;
    int freq[n];
    for(int i=0;i<n;i++){
        cin>>target;
        freq[i]=target;
    }
    sort(freq,freq+n);
    cin>>m;
    while(m--){
        cin>>target;
        binarySearch(freq,target,0,n) ? cout<<"1\n" : cout<<"0\n";
    }
}