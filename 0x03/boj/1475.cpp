//
// Created by wisdom99 on 2024-01-08.
//
#include <iostream>

using namespace std;

int freq[2000001];
bool occured[2000001];
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int long x;
    cin>>n;
    int result=0;
    while(n--){
        int num;
        cin>>num;
        freq[num]++; //등장 시 해당 인덱스에 기록
    }
    cin>>x;
    for(int i=0;i<1000001;i++){
        if(freq[i]+freq[x-i]==2){
            result++;
            occured[]
        }
    }
    cout<<result;
}