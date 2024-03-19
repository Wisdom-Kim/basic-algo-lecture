//
// Created by wisdom99 on 2024-03-18.
//
#include <iostream>
#include <deque>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m,temp;
    cin>>n>>m;
    deque <int> arr1;
    deque <int> arr2;
    deque <int> res;

    int resLength = n+m;
    while(n--) { cin>>temp ; arr1.push_back(temp);}
    while(m--) { cin>>temp ; arr2.push_back(temp);}

    while(res.size()<resLength){
        if(arr1.empty()) temp = arr2.front();
        else if(arr2.empty()) temp =arr1.front();
        else temp = arr1.front()>arr2.front()? arr2.front() : arr1.front();

        res.push_back(temp);
        temp==arr1.front() ? arr1.pop_front() : arr2.pop_front();
    }
    for(auto c:res) cout<<c<<" ";
}