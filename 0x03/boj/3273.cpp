//
// Created by wisdom99 on 2024-01-08.
//
//
// Created by wisdom99 on 2024-01-08.
//
#include <iostream>

using namespace std;

int freq[2000001];

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,x,num;
    int ans=0;
    cin>>n;
    while(n--){
        cin>>num;
        freq[num]++; //등장 시 해당 인덱스에 기록
    }
    cin>>x;
    for(int i=1;i<(x+1)/2;++i){
        if (freq[i] ==1 && freq[x - i] == 1) ans++;
    }
    cout<<ans;
}