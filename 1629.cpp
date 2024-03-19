//
// Created by wisdom99 on 2024-02-04.
//
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int> graph[1001];
bool visit[1001];
int n,m;

void BFS(int start){
    queue<int> q;
    q.push(start);
    visit[start]=true;

    while(!q.empty()){
        auto a=q.front();
        q.pop();
        for(auto area:graph[a]){
            if(visit[area]) continue;//방문했다면 패스
            visit[area]=true;//방문처리
            q.push(area);
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int answer=0;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(visit[i]) continue;
        //방문 지점이 아닐 경우
        BFS(i);
        answer++;
    }
    cout<<answer;
}