//
// Created by wisdom99 on 2024-01-15.
//
#include<iostream>
#include<queue>

#define Y first
#define X second

int tomato[10002][10002];
int dist[10002][10002]; //거리를 담아두는 배열

using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //정답은, 모든 구역에서 bfs를 실행했을 때 나오는 값 중에서의 최대 수
    int m,n;
    cin>>m>>n;
    queue<pair<int,int>> q; //bfs용 큐
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            cin>>tomato[i][j];
            if(tomato[i][j]==1)
                q.push({i,j});
            if(tomato[i][j]==0) dist[i][j]=-1; //익혀야 할 토마토가 있음
        }
    }
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int cnt=0;

    while(!q.empty()){
        auto a=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int newY=a.Y+dy[i];
            int newX=a.X+dx[i];

            if(newX>=m||newX<0||newY>=n||newY<0) continue;//범위 밖은 패스
            if(dist[newY][newX]!=-1) continue;//토마토가 없는 곳은 패스
            dist[newY][newX]=dist[a.Y][a.X]+1;
            q.push({newY,newX});
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dist[i][j]==-1){
                //안 익은 토마토가 있음
                cout<<-1;
                return 0;
            }
            cnt=max(cnt,dist[i][j]);
        }
    }
    cout<<cnt;
}