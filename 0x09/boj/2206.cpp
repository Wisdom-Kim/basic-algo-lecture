//
// Created by wisdom99 on 2024-01-24.
//
#include <iostream>
#include <tuple>
#include <queue>
//이동 가능여부를 나타내는 배열을 만들자

int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int dist[1000][1000][2];//마지막 요소 0: 벽을 부수지 않고 최대이동 가능,1:1개까지 부순 상태에서 이동가능

using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    string map[n]; //지도

    for (int i = 0; i < n; ++i) {
        cin>>map[i];
        for (int j = 0; j < m; ++j)
            dist[i][j][0] = dist[i][j][1] = -1;
    }
    queue<tuple<int,int,int>> q; q.push({0,0,0});

    dist[0][0][0]=dist[0][0][1]=1;

    while(!q.empty()){
        auto a=q.front();q.pop();
        int y,x,broken;
        tie(y,x,broken)=a;

        if(x==m-1&&y==n-1){
            cout<<dist[y][x][broken];
            return 0;}
        for(int i=0;i<4;i++){
            int nX=x+dx[i];
            int nY=y+dy[i];
            if(nX<0||nY<0||nX>=m||nY>=n) continue;
            //다음 위치가 벽이고, 아직 broken값이 없을 경우
            if(broken==0 && map[nY][nX]=='1'&& dist[nY][nX][broken]==-1){
                dist[nY][nX][1]=dist[y][x][0]+1;
                q.push({nY,nX,1});
            }
            if(map[nY][nX]=='0' && dist[nY][nX][broken]==-1){
                dist[nY][nX][broken]=dist[y][x][broken]+1;
                q.push({nY,nX,broken});
            }
        }
    }
    cout<<-1;
}