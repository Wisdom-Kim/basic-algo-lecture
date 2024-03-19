//
// Created by wisdom99 on 2024-01-28.
#include<iostream>
#include<deque>
#define MAX 200002
using namespace std;

int dist[MAX];//k까지 가는데의 최단 거리

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    deque<int> q;
    cin >>n>>k;
    fill(dist,dist+200000,-1);

    //방문
    q.push_front(n);
    dist[n]=0;

    while(!q.empty()){
        auto a=q.front();q.pop_front();
        for(auto c:{a-1,a+1,a*2}){
            if(c<0||c>=MAX) continue;
            if(dist[c]!=-1) continue;
            if(c==a*2) {
                //최대한 먼저 방문할 수 있도록 front에 push
                q.push_front(c);
                dist[c]=dist[a];
            }
            else {
                dist[c]=dist[a]+1;
                q.push_back(c);
            }
        }
    }
    cout<<dist[k];

}