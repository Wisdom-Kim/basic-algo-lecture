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
    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;
    int dist[f+1];
    fill(dist,dist+(f+1),-1);

    queue<int> q;
    q.push(s);
    dist[s]=0;//강호의 현재 위치
    while(!q.empty()){
        auto c=q.front();q.pop();
        for(int nxt:{c+u,c-d}){
            if(nxt<1||nxt>f) continue;
            if(dist[nxt]!=-1)continue;
            dist[nxt]=dist[c]+1;
            q.push(nxt);
        }
    }
    dist[g]!=-1 ? cout<<dist[g] : cout<<"use the stairs";
}