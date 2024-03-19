//
// Created by wisdom99 on 2024-01-16.
//
#include <iostream>
#include <queue>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    queue<int> q;//동생의 이동 후보
    int cnt=0;
    int dist[100001];
    int MAX=100000;
    fill(dist,dist+100001,-1);
    dist[n]=0;
    q.push(n);
    while(dist[k]==-1){
        auto c=q.front();q.pop();
        for(int nxt:{c-1,c+1,c*2}){
            if(nxt<0 || nxt>100000) continue;
            if(dist[nxt]!=-1)continue;
            dist[nxt]=dist[c]+1;
            q.push(nxt);
        }
    }
    cout<<dist[k];



}