//
// Created by wisdom99 on 2024-01-28.
#include<iostream>
#include<queue>
#include <stack>
#define MAX 200002
using namespace std;

int dist[MAX];//k까지 가는데의 최단 거리
int pre[MAX]; //직전에 방문한 노드를 표시
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    queue<int> q;
    cin >>n>>k;
    fill(dist,dist+MAX,-1);
    fill(pre,pre+MAX,-1);
    //방문
    q.push(n);
    dist[n]=0;
    pre[n]=n;

    while(!q.empty()){
        auto a=q.front();q.pop();
        for(auto c:{a-1,a+1,a*2}){
            if(c<0||c>=MAX) continue;
            if(dist[c]!=-1) continue;
            dist[c]=dist[a]+1;
            pre[c]=a;
            q.push(c);
        }
    }
    cout<<dist[k]<<"\n";

    int cnt=k;
    stack<int> pos;
    pos.push(k);
    while(pre[cnt]!=n){
        pos.push(pre[cnt]);
        cnt=pre[cnt];
    }
    if(n!=k) pos.push(n);

    while(!pos.empty()){
        cout<<pos.top()<<" ";
        pos.pop();
    }

}